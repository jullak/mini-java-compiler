#include <stdexcept>

#include "../Elements.hpp"
#include "ScopeBuilderVisitor.hpp"


ScopeBuilderVisitor::ScopeBuilderVisitor()
  : root_(nullptr)
  , current_layer_(&root_)
{
  current_child_number_.push(0);
}

void ScopeBuilderVisitor::increase_current_child_() {
  int child_num = current_child_number_.top();
  current_child_number_.pop();
  current_child_number_.push(child_num + 1);
}


void ScopeBuilderVisitor::visit(PlusExpression * expression) {
  expression->left_->accept(this);
  expression->right_->accept(this);
}
void ScopeBuilderVisitor::visit(MinusExpression * expression) {
  expression->left_->accept(this);
  expression->right_->accept(this);
}
void ScopeBuilderVisitor::visit(StarExpression * expression) {
  expression->left_->accept(this);
  expression->right_->accept(this);
}
void ScopeBuilderVisitor::visit(SlashExpression * expression) {
  expression->left_->accept(this);
  expression->right_->accept(this);
}
void ScopeBuilderVisitor::visit(ProcExpression * expression) {
  expression->left_->accept(this);
  expression->right_->accept(this);
}
void ScopeBuilderVisitor::visit(AndExpression * expression) {
  expression->left_->accept(this);
  expression->right_->accept(this);
}
void ScopeBuilderVisitor::visit(OrExpression * expression) {
  expression->left_->accept(this);
  expression->right_->accept(this);
}
void ScopeBuilderVisitor::visit(LessExpression * expression) {
  expression->left_->accept(this);
  expression->right_->accept(this);
}
void ScopeBuilderVisitor::visit(GreatExpression * expression) {
  expression->left_->accept(this);
  expression->right_->accept(this);
}
void ScopeBuilderVisitor::visit(EqualExpression * expression) {
  expression->left_->accept(this);
  expression->right_->accept(this);
}
void ScopeBuilderVisitor::visit(ArrayExpression * expression) {
  expression->left_->accept(this);
  expression->index_->accept(this);
}
void ScopeBuilderVisitor::visit(LengthExpression * expression) {
  expression->left_->accept(this);
}
void ScopeBuilderVisitor::visit(NewArrayExpression * expression) {
  expression->expression_->accept(this);
}
void ScopeBuilderVisitor::visit(NotExpression * expression) {
  expression->left_->accept(this);
}
void ScopeBuilderVisitor::visit(NumberExpression * expression) {}
void ScopeBuilderVisitor::visit(BoolExpression * expression) {}
void ScopeBuilderVisitor::visit(IdentifierExpression * expression) {
  if (!current_layer_->is_declared(expression->identifier_)) {
    throw std::runtime_error("Use var before definition!");
  }
}
void ScopeBuilderVisitor::visit(UnaryMinusExpression * expression) {
  expression->expression_->accept(this);
}
void ScopeBuilderVisitor::visit(ParenExpression * expression) {
  expression->expression_->accept(this);
}


void ScopeBuilderVisitor::visit(StatementsList * statement) {
  for (auto st : statement->statements_) {
    st->accept(this);
  }
}
void ScopeBuilderVisitor::visit(IfStatement * statement) {
  statement->condition_->accept(this);

  increase_current_child_();
  current_layer_->add_child_layer();

  current_layer_ = current_layer_->switch_to_child(current_child_number_.top() - 1);
  statement->statement_->accept(this);
  current_layer_ = current_layer_->switch_to_parent();
}
void ScopeBuilderVisitor::visit(IfElseStatement * statement) {
  statement->condition_->accept(this);

  increase_current_child_();
  current_layer_->add_child_layer();
  current_layer_ = current_layer_->switch_to_child(current_child_number_.top() - 1);
  statement->statementIf_->accept(this);
  current_layer_ = current_layer_->switch_to_parent();

  increase_current_child_();
  current_layer_->add_child_layer();
  current_layer_ = current_layer_->switch_to_child(current_child_number_.top() - 1);
  statement->statementElse_->accept(this);
  current_layer_ = current_layer_->switch_to_parent();
}
void ScopeBuilderVisitor::visit(WhileStatement * statement) {
  statement->condition_->accept(this);

  increase_current_child_();

  current_layer_->add_child_layer();
  current_layer_ = current_layer_->switch_to_child(current_child_number_.top() - 1);
  statement->statement_->accept(this);
  current_layer_ = current_layer_->switch_to_parent();
}
void ScopeBuilderVisitor::visit(ReturnStatement * statement) {
  statement->returned_->accept(this);
}
void ScopeBuilderVisitor::visit(AssertStatement * statement) {
  statement->checked_->accept(this);
}
void ScopeBuilderVisitor::visit(OutputStatement * statement) {
  statement->information_->accept(this);
}
void ScopeBuilderVisitor::visit(BraceStatement * statement) {
  increase_current_child_();
  current_layer_->add_child_layer();

  current_layer_ = current_layer_->switch_to_child(current_child_number_.top() - 1);
  statement->statements_->accept(this);
  current_layer_ = current_layer_->switch_to_parent();
}
void ScopeBuilderVisitor::visit(AssignStatement * statement) {
  statement->lvalue_->accept(this);
  statement->rvalue_->accept(this);
}
void ScopeBuilderVisitor::visit(DeclarationStatement * statement) {
  statement->declaration_->accept(this);
}

void ScopeBuilderVisitor::visit(IdentifierLvalue * lvalue) {
  if (!current_layer_->is_declared(lvalue->identifier_)) {
    throw std::runtime_error("Use var before definition!");
  }
}
void ScopeBuilderVisitor::visit(ElementLvalue * lvalue) {
  if (!current_layer_->is_declared(lvalue->identifier_)) {
    throw std::runtime_error("Use var before definition!");
  }

  lvalue->expression_->accept(this);
}

void ScopeBuilderVisitor::visit(Declaration * declaration) {
  current_layer_->declare_variable(declaration->identifier_, declaration->type_->type_);
}