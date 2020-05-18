#pragma once

#include <fstream>
#include <string>

#include "Visitor.hpp"

class PrintVisitor : public Visitor {
public:
  explicit PrintVisitor(const std::string & ast_file);
  ~PrintVisitor() override;

  void visit(PlusExpression * expression) override;
  void visit(MinusExpression * expression) override;
  void visit(StarExpression * expression) override;
  void visit(SlashExpression * expression) override;
  void visit(ProcExpression * expression) override;
  void visit(AndExpression * expression) override;
  void visit(OrExpression * expression) override;
  void visit(LessExpression * expression) override;
  void visit(GreatExpression * expression) override;
  void visit(EqualExpression * expression) override;
  void visit(ArrayExpression * expression) override;
  void visit(LengthExpression * expression) override;
  void visit(NewArrayExpression * expression) override;
  void visit(NotExpression * expression) override;
  void visit(NumberExpression * expression) override;
  void visit(BoolExpression * expression) override;
  void visit(IdentifierExpression * expression) override;
  void visit(UnaryMinusExpression * expression) override;
  void visit(ParenExpression * expression) override;

  void visit(StatementsList * statement) override;
  void visit(IfStatement * statement) override;
  void visit(IfElseStatement * statement) override;
  void visit(WhileStatement * statement) override;
  void visit(ReturnStatement * statement) override;
  void visit(AssertStatement * statement) override;
  void visit(OutputStatement * statement) override;
  void visit(BraceStatement * statement) override;
  void visit(AssignStatement * statement) override;
  void visit(DeclarationStatement * statement) override;

  void visit(IdentifierLvalue * lvalue) override;
  void visit(ElementLvalue * lvalue) override;

  void visit(ArrayType * type) override;
  void visit(SimpleType * type) override;

  void visit(Declaration * declaration) override;
private:
  std::ofstream ast_stream_;
  size_t tabs_count_ = 0;

  void print_tabs_();
};