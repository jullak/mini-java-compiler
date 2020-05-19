#include <cassert>
#include <iostream>

#include "InterpretVisitor.hpp"

#include "IntArrayObject.hpp"
#include "IntObject.hpp"
#include "BoolArrayObject.hpp"
#include "BoolObject.hpp"

InterpretVisitor::InterpretVisitor(ScopeLayer *root)
  : root_(root)
  , current_layer_(root)
{
  current_child_number_.push(0);
}

void InterpretVisitor::visit(PlusExpression * expression) {
  tos_value_ = std::make_shared<IntObject>(accept(expression->left_)->get_int() + accept(expression->right_)->get_int());
}
void InterpretVisitor::visit(MinusExpression * expression) {
  tos_value_ = std::make_shared<IntObject>(accept(expression->left_)->get_int() - accept(expression->right_)->get_int());
}
void InterpretVisitor::visit(StarExpression * expression) {
  tos_value_ = std::make_shared<IntObject>(accept(expression->left_)->get_int() * accept(expression->right_)->get_int());
}
void InterpretVisitor::visit(SlashExpression * expression) {
  tos_value_ = std::make_shared<IntObject>(accept(expression->left_)->get_int() / accept(expression->right_)->get_int());
}
void InterpretVisitor::visit(ProcExpression * expression) {
  tos_value_ = std::make_shared<IntObject>(accept(expression->left_)->get_int() % accept(expression->right_)->get_int());
}
void InterpretVisitor::visit(AndExpression * expression) {
  tos_value_ = std::make_shared<BoolObject>(accept(expression->left_)->get_bool() && accept(expression->right_)->get_bool());
}
void InterpretVisitor::visit(OrExpression * expression) {
  tos_value_ = std::make_shared<BoolObject>(accept(expression->left_)->get_bool() || accept(expression->right_)->get_bool());
}
void InterpretVisitor::visit(LessExpression * expression) {
  tos_value_ = std::make_shared<BoolObject>(accept(expression->left_)->get_int() < accept(expression->right_)->get_int());
}
void InterpretVisitor::visit(GreatExpression * expression) {
  tos_value_ = std::make_shared<BoolObject>(accept(expression->left_)->get_int() > accept(expression->right_)->get_int());
}
void InterpretVisitor::visit(EqualExpression * expression) {
  auto left = accept(expression->left_);
  auto right = accept(expression->right_);

  if (left->is_int()) {
    tos_value_ = std::make_shared<BoolObject>(left->get_int() == right->get_int());
  } else if (left->is_bool()) {
    tos_value_ = std::make_shared<BoolObject>(left->get_bool() == right->get_bool());
  }
}
void InterpretVisitor::visit(ArrayExpression * expression) {
  auto index = accept(expression->index_);
  auto array = accept(expression->left_);

  if (array->is_int_array()) {
    tos_value_ = std::make_shared<IntObject>(array->get_int_array()[index->get_int()]);
  } else if (array->is_bool_array()) {
    tos_value_ = std::make_shared<BoolObject>(array->get_bool_array()[index->get_int()]);
  }
}
void InterpretVisitor::visit(LengthExpression * expression) {
  auto array = accept(expression->left_);

  if (array->is_int_array()) {
    tos_value_ = std::make_shared<IntObject>(array->get_int_array().size());
  } else if (array->is_bool_array()) {
    tos_value_ = std::make_shared<IntObject>(array->get_bool_array().size());
  }
}
void InterpretVisitor::visit(NewArrayExpression * expression) {
  if (expression->type_->type_ == INT) {
    tos_value_ = std::make_shared<IntArrayObject>(accept(expression->expression_)->get_int());
  } else if (expression->type_->type_ == BOOL) {
    tos_value_ = std::make_shared<BoolArrayObject>(accept(expression->expression_)->get_int());
  }
}
void InterpretVisitor::visit(NotExpression * expression) {
  tos_value_ = std::make_shared<BoolObject>(!accept(expression->left_)->get_bool());
}
void InterpretVisitor::visit(NumberExpression * expression) {
  tos_value_ = std::make_shared<IntObject>(expression->number_);
}
void InterpretVisitor::visit(BoolExpression * expression) {
  tos_value_ = std::make_shared<BoolObject>(expression->boolean_);
}
void InterpretVisitor::visit(IdentifierExpression * expression) {
  tos_value_ = current_layer_->get_variable(expression->identifier_);
}
void InterpretVisitor::visit(UnaryMinusExpression * expression) {
  tos_value_ = std::make_shared<IntObject>(-accept(expression->expression_)->get_int());
}
void InterpretVisitor::visit(ParenExpression * expression) {
  tos_value_ = accept(expression->expression_);
}

void InterpretVisitor::visit(StatementsList * statement) {
  for (auto st : statement->statements_){
    accept(st);
  }
}
void InterpretVisitor::visit(IfStatement * statement) {
  auto condition = accept(statement->condition_)->get_bool();
  if (condition) {
    accept(statement->statement_);
  }
}
void InterpretVisitor::visit(IfElseStatement * statement) {
  auto condition = accept(statement->condition_)->get_bool();

  if (condition) {
    accept(statement->statementIf_);
    increase_current_child_();
  } else {
    increase_current_child_();
    accept(statement->statementElse_);
  }
}
void InterpretVisitor::visit(WhileStatement * statement) {
  while (accept(statement->condition_)->get_bool()) {
    accept(statement->statement_);
    decrease_current_child_();
  }
  increase_current_child_();
}
void InterpretVisitor::visit(ReturnStatement * statement) { }
void InterpretVisitor::visit(AssertStatement * statement) {
  assert(accept(statement->checked_)->get_bool());
}
void InterpretVisitor::visit(OutputStatement * statement) {
  std::cout << accept(statement->information_)->get_int() << std::endl;
}
void InterpretVisitor::visit(BraceStatement * statement) {
  begin_scope_();
  accept(statement->statements_);
  end_scope_();
}
void InterpretVisitor::visit(DeclarationStatement * statement) {}

void InterpretVisitor::visit(IdentifierAssignStatement * statement) {
  auto lv = current_layer_->get_variable(statement->identifier_);
  auto lv_type = current_layer_->get_variable_type(statement->identifier_);

  if (nullptr == lv) {
    current_layer_->init_variable(statement->identifier_, accept(statement->rvalue_));
  } else if (lv_type == INT) {
    lv->set_int(accept(statement->rvalue_)->get_int());
  } else if (lv_type == BOOL) {
    lv->set_bool(accept(statement->rvalue_)->get_bool());
  }
}
void InterpretVisitor::visit(ArrayAssignStatement * statement) {
  auto lv = current_layer_->get_variable(statement->identifier_);
  auto index = accept(statement->expression_)->get_int();

  if (lv->is_int_array()) {
    lv->get_int_array()[index] = accept(statement->rvalue_)->get_int();
  } else if (lv->is_bool_array()) {
    lv->get_bool_array()[index] = accept(statement->rvalue_)->get_bool();
  }
}

void InterpretVisitor::visit(ArrayType * type) {}
void InterpretVisitor::visit(SimpleType * type) {}

void InterpretVisitor::visit(Declaration * declaration) {}


void InterpretVisitor::begin_scope_() {
  current_layer_ = current_layer_->switch_to_child(current_child_number_.top());
  current_child_number_.push(0);
}

void InterpretVisitor::end_scope_() {
  current_layer_ = current_layer_->switch_to_parent();
  current_child_number_.pop();

  increase_current_child_();
}

void InterpretVisitor::increase_current_child_() {
  int child_num = current_child_number_.top();
  current_child_number_.pop();
  current_child_number_.push(child_num + 1);
}

void InterpretVisitor::decrease_current_child_() {
  int child_num = current_child_number_.top();
  current_child_number_.pop();
  current_child_number_.push(child_num - 1);
}