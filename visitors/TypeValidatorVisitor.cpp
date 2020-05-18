#include <stdexcept>

#include "PrimitiveTypes.hpp"
#include "TypeValidatorVisitor.hpp"

TypeValidatorVisitor::TypeValidatorVisitor(ScopeLayer * root)
  : root_(root)
  , current_layer_(root)
{
  current_child_number_.push(0);
}

void TypeValidatorVisitor::visit(PlusExpression * expression) {
  if (accept(expression->left_) != INT || accept(expression->right_) != INT) {
    throw std::runtime_error("Incompatible types, expected: int; + PlusExpression");
  }

  tos_value_ = INT;
}
void TypeValidatorVisitor::visit(MinusExpression * expression) {
  if (accept(expression->left_) != INT || accept(expression->right_) != INT) {
    throw std::runtime_error("Incompatible types, expected: int; - MinusExpression");
  }

  tos_value_ = INT;
}
void TypeValidatorVisitor::visit(StarExpression * expression) {
  if (accept(expression->left_) != INT || accept(expression->right_) != INT) {
    throw std::runtime_error("Incompatible types, expected: int; * StarExpression");
  }

  tos_value_ = INT;
}
void TypeValidatorVisitor::visit(SlashExpression * expression) {
  if (accept(expression->left_) != INT || accept(expression->right_) != INT) {
    throw std::runtime_error("Incompatible types, expected: int; / SlashExpression");
  }

  tos_value_ = INT;
}
void TypeValidatorVisitor::visit(ProcExpression * expression) {
  if (accept(expression->left_) != INT || accept(expression->right_) != INT) {
    throw std::runtime_error("Incompatible types, expected: int; % ProcExpression");
  }

  tos_value_ = INT;
}
void TypeValidatorVisitor::visit(AndExpression * expression) {
  if (accept(expression->left_) != BOOL || accept(expression->right_) != BOOL) {
    throw std::runtime_error("Incompatible types, expected: bool; && AndExpression");
  }

  tos_value_ = BOOL;
}
void TypeValidatorVisitor::visit(OrExpression * expression) {
  if (accept(expression->left_) != BOOL || accept(expression->right_) != BOOL) {
    throw std::runtime_error("Incompatible types, expected: bool; || OrExpression");
  }

  tos_value_ = BOOL;
}
void TypeValidatorVisitor::visit(LessExpression * expression) {
  if (accept(expression->left_) != INT || accept(expression->right_) != INT) {
    throw std::runtime_error("Incompatible types, expected: bool; < LessExpression");
  }

  tos_value_ = BOOL;
}
void TypeValidatorVisitor::visit(GreatExpression * expression) {
  if (accept(expression->left_) != INT || accept(expression->right_) != INT) {
    throw std::runtime_error("Incompatible types, expected: bool; > GreatExpression");
  }

  tos_value_ = BOOL;
}
void TypeValidatorVisitor::visit(EqualExpression * expression) {
  if (accept(expression->left_) != accept(expression->right_)) {
    throw std::runtime_error("Incompatible types; == EqualExpression");
  }

  tos_value_ = BOOL;
}
void TypeValidatorVisitor::visit(ArrayExpression * expression) {
  PrimitiveTypes left_expr_type = accept(expression->left_);
  if (left_expr_type != INT_ARRAY && left_expr_type != BOOL_ARRAY) {
    throw std::runtime_error("Incompatible types, not array; ident[] ArrayExpression");
  }

  if (left_expr_type == INT_ARRAY) tos_value_ = INT;
  if (left_expr_type == BOOL_ARRAY) tos_value_ = BOOL;
}
void TypeValidatorVisitor::visit(LengthExpression * expression) {
  PrimitiveTypes left_expr_type = accept(expression->left_);

  if (left_expr_type != INT_ARRAY && left_expr_type != BOOL_ARRAY) {
    throw std::runtime_error("Incompatible types, not array; .len LengthExpression");
  }

  tos_value_ = INT;
}
void TypeValidatorVisitor::visit(NewArrayExpression * expression) {
  if (accept(expression->expression_) != INT) {
    throw std::runtime_error("Incompatible types, expected: int; new[] NewArrayExpression");
  }

  if (expression->type_->type_ == INT) tos_value_ = INT_ARRAY;
  if (expression->type_->type_ == BOOL) tos_value_ = BOOL_ARRAY;
}
void TypeValidatorVisitor::visit(NotExpression * expression) {
  if (accept(expression->left_) != BOOL) {
    throw std::runtime_error("Incompatible types, expected: bool; ! NotExpression");
  }

  tos_value_ = BOOL;
}
void TypeValidatorVisitor::visit(NumberExpression * expression) {
  tos_value_ = INT;
}
void TypeValidatorVisitor::visit(BoolExpression * expression) {
  tos_value_ = BOOL;
}
void TypeValidatorVisitor::visit(IdentifierExpression * expression) {
  tos_value_ = current_layer_->get_variable_type(expression->identifier_);
}
void TypeValidatorVisitor::visit(UnaryMinusExpression * expression) {
  if (accept(expression->expression_) != INT) {
    throw std::runtime_error("Incompatible types, expected: int; - UnaryMinusExpression");
  }

  tos_value_ = INT;
}
void TypeValidatorVisitor::visit(ParenExpression * expression) {
  tos_value_ = accept(expression->expression_);
}

void TypeValidatorVisitor::visit(StatementsList * statement) {
  for (auto st: statement->statements_) {
    accept(st);
  }
}
void TypeValidatorVisitor::visit(IfStatement * statement) {
  if (accept(statement->condition_) != BOOL) {
    throw std::runtime_error("Incompatible types, expected: bool; condition in IfStatement");
  }

  accept(statement->statement_);
}
void TypeValidatorVisitor::visit(IfElseStatement * statement) {
  if (accept(statement->condition_) != BOOL) {
    throw std::runtime_error("Incompatible types, expected: bool; condition in IfElseStatement");
  }

  accept(statement->statementIf_);
  accept(statement->statementElse_);
}
void TypeValidatorVisitor::visit(WhileStatement * statement) {
  if (accept(statement->condition_) != BOOL) {
    throw std::runtime_error("Incompatible types, expected: bool; condition in WhileStatement");
  }

  accept(statement->statement_);
}
void TypeValidatorVisitor::visit(ReturnStatement * statement) {
  accept(statement->returned_);
}
void TypeValidatorVisitor::visit(AssertStatement * statement) {
  accept(statement->checked_);
}
void TypeValidatorVisitor::visit(OutputStatement * statement) {
  accept(statement->information_);
}
void TypeValidatorVisitor::visit(BraceStatement * statement) {
  begin_scope_();
  accept(statement->statements_);
  end_scope_();
}
void TypeValidatorVisitor::visit(AssignStatement * statement) {
  if (accept(statement->lvalue_) != accept(statement->rvalue_)) {
    throw std::runtime_error("Incompatible types in AssignStatement");
  }
}
void TypeValidatorVisitor::visit(DeclarationStatement * statement) {
  accept(statement->declaration_);
}

void TypeValidatorVisitor::visit(IdentifierLvalue * lvalue) {
  tos_value_ = current_layer_->get_variable_type(lvalue->identifier_);
}
void TypeValidatorVisitor::visit(ElementLvalue * lvalue) {
  if (accept(lvalue->expression_) != INT) {
    throw std::runtime_error("Incompatible types, expected: int; [expr] in ElementLvalue");
  }

  tos_value_ = current_layer_->get_variable_type(lvalue->identifier_);
  if (tos_value_ == INT_ARRAY) tos_value_ = INT;
  if (tos_value_ == BOOL_ARRAY) tos_value_ = BOOL;
}

void TypeValidatorVisitor::visit(ArrayType * type) {
  tos_value_ = type->type_;
}
void TypeValidatorVisitor::visit(SimpleType * type) {
  tos_value_ = type->type_;
}

void TypeValidatorVisitor::visit(Declaration * declaration) {
  tos_value_ = declaration->type_->type_;
}

void TypeValidatorVisitor::begin_scope_() {
  current_layer_ = current_layer_->switch_to_child(current_child_number_.top());

  int child_num = current_child_number_.top();
  current_child_number_.pop();
  current_child_number_.push(child_num + 1);

  current_child_number_.push(0);
}

void TypeValidatorVisitor::end_scope_() {
  current_layer_ = current_layer_->switch_to_parent();
  current_child_number_.pop();
}