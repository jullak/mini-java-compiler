#include "../Elements.hpp"
#include "PrintVisitor.hpp"

PrintVisitor::PrintVisitor(const std::string &ast_file)
  : ast_stream_(ast_file)
{}

PrintVisitor::~PrintVisitor() {
  ast_stream_.close();
}

void PrintVisitor::visit(PlusExpression * expression) {
  print_tabs_();
  ast_stream_ << "+ - PlusExpression is:" << std::endl;

  ++tabs_count_;
  expression->left_->accept(this);
  expression->right_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(MinusExpression * expression) {
  print_tabs_();
  ast_stream_ << "- - MinusExpression is:" << std::endl;

  ++tabs_count_;
  expression->left_->accept(this);
  expression->right_->accept(this);
  --tabs_count_;
};
void PrintVisitor::visit(StarExpression * expression) {
  print_tabs_();
  ast_stream_ << "* - StarExpression is:" << std::endl;

  ++tabs_count_;
  expression->left_->accept(this);
  expression->right_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(SlashExpression * expression) {
  print_tabs_();
  ast_stream_ << "SlashExpression is:" << std::endl;

  ++tabs_count_;
  expression->left_->accept(this);
  expression->right_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(ProcExpression * expression) {
  print_tabs_();
  ast_stream_ << "% - ProcExpression is:" << std::endl;

  ++tabs_count_;
  expression->left_->accept(this);
  expression->right_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(AndExpression * expression) {
  print_tabs_();
  ast_stream_ << "&& - AndExpression is:" << std::endl;

  ++tabs_count_;
  expression->left_->accept(this);
  expression->right_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(OrExpression * expression) {
  print_tabs_();
  ast_stream_ << "|| - OrExpression is:" << std::endl;

  ++tabs_count_;
  expression->left_->accept(this);
  expression->right_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(LessExpression * expression) {
  print_tabs_();
  ast_stream_ << "< - LessExpression is:" << std::endl;

  ++tabs_count_;
  expression->left_->accept(this);
  expression->right_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(GreatExpression * expression) {
  print_tabs_();
  ast_stream_ << "> - GreatExpression is:" << std::endl;

  ++tabs_count_;
  expression->left_->accept(this);
  expression->right_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(EqualExpression * expression) {
  print_tabs_();
  ast_stream_ << "== - EqualExpression is:" << std::endl;

  ++tabs_count_;
  expression->left_->accept(this);
  expression->right_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(ArrayExpression * expression) {
  print_tabs_();
  ast_stream_ << "[] - ArrayExpression is:" << std::endl;

  ++tabs_count_;
  expression->left_->accept(this);
  expression->index_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(LengthExpression * expression) {
  print_tabs_();
  ast_stream_ << ".length - LengthExpression is:" << std::endl;

  ++tabs_count_;
  expression->left_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(NewArrayExpression * expression) {
  print_tabs_();
  ast_stream_ << "new [] - NewArrayExpression is:" << std::endl;

  ++tabs_count_;
  expression->type_->accept(this);
  expression->expression_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(NotExpression * expression) {
  print_tabs_();
  ast_stream_ << "! - NotExpression is:" << std::endl;

  ++tabs_count_;
  expression->left_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(NumberExpression * expression) {
  print_tabs_();
  ast_stream_ << "NumberExpression is: " << expression->number_ << std::endl;;
}
void PrintVisitor::visit(BoolExpression * expression) {
  print_tabs_();
  ast_stream_ << "BoolExpression is: " << expression->boolean_ << std::endl;
}
void PrintVisitor::visit(IdentifierExpression * expression) {
  print_tabs_();
  ast_stream_ << "IdentifierExpression is: " << expression->identifier_ << std::endl;
}
void PrintVisitor::visit(UnaryMinusExpression * expression) {
  print_tabs_();
  ast_stream_ << "- - UnaryMinusExpression is:" << std::endl;

  ++tabs_count_;
  expression->expression_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(ParenExpression * expression) {
  print_tabs_();
  ast_stream_ << "() - ParenExpression is:" << std::endl;

  ++tabs_count_;
  expression->expression_->accept(this);
  --tabs_count_;
}

void PrintVisitor::visit(StatementsList * statement) {
  print_tabs_();
  ast_stream_ << "{} - StatementsList is:" << std::endl;

  ++tabs_count_;
  for (auto st : statement->statements_) {
    st->accept(this);
  }
  --tabs_count_;
}
void PrintVisitor::visit(IfStatement * statement) {
  print_tabs_();
  ast_stream_ << "if(...) - IfStatement is:" << std::endl;

  ++tabs_count_;
  statement->condition_->accept(this);
  statement->statement_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(IfElseStatement * statement) {
  print_tabs_();
  ast_stream_ << "if(...) else - IfElseStatement is:" << std::endl;

  ++tabs_count_;
  statement->condition_->accept(this);
  statement->statementIf_->accept(this);
  statement->statementElse_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(WhileStatement * statement) {
  print_tabs_();
  ast_stream_ << "while(...) - WhileStatement is:" << std::endl;

  ++tabs_count_;
  statement->condition_->accept(this);
  statement->statement_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(ReturnStatement * statement) {
  print_tabs_();
  ast_stream_ << "return - ReturnStatement is:" << std::endl;

  ++tabs_count_;
  statement->returned_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(AssertStatement * statement) {
  print_tabs_();
  ast_stream_ << "assert - AssertStatement is:" << std::endl;

  ++tabs_count_;
  statement->checked_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(OutputStatement * statement) {
  print_tabs_();
  ast_stream_ << "System.out.println(...) - OutputStatement is:" << std::endl;

  ++tabs_count_;
  statement->information_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(BraceStatement * statement) {
  print_tabs_();
  ast_stream_ << "{...} - BraceStatement is:" << std::endl;

  ++tabs_count_;
  statement->statements_->accept(this);
  --tabs_count_;
}
void PrintVisitor::visit(DeclarationStatement * statement) {
  print_tabs_();
  ast_stream_ << "DeclarationStatement is:" << std::endl;

  ++tabs_count_;
  statement->declaration_->accept(this);
  --tabs_count_;
}

void PrintVisitor::visit(IdentifierAssignStatement * statement) {
  print_tabs_();
  ast_stream_ << "= - IdentifierAssignStatement is: " << statement->identifier_ << std::endl;

  statement->rvalue_->accept(this);
}
void PrintVisitor::visit(ArrayAssignStatement * statement) {
  print_tabs_();
  ast_stream_ << "[]= - ArrayAssignStatement is: " << statement->identifier_ << "[]" <<std::endl;

  statement->expression_->accept(this);
  statement->rvalue_->accept(this);
}

void PrintVisitor::visit(ArrayType * type) {
  print_tabs_();
  ast_stream_ << "type[] - ArrayType is:" << type->type_ << ", 2 - INT[], 3 - BOOL[]" << std::endl;
}
void PrintVisitor::visit(SimpleType * type) {
  print_tabs_();
  ast_stream_ << "Simple type is:" << type->type_ << ", 0 - INT, 1 - BOOL" << std::endl;
}

void PrintVisitor::visit(Declaration * declaration) {
  print_tabs_();
  ast_stream_ << "Declaration is:" << "type -" << std::endl;

  declaration->type_->accept(this);
  print_tabs_();
  ast_stream_ << " name - " << declaration->identifier_ << std::endl;
}

void PrintVisitor::print_tabs_() {
  for (int i = 0; i < tabs_count_; ++i) {
    ast_stream_ << "\t";
  }
}