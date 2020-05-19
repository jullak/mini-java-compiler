#pragma once

#include <stack>

#include "TemplateVisitor.hpp"
#include "ScopeLayer.hpp"

class TypeValidatorVisitor : public TemplateVisitor<PrimitiveTypes> {
public:
  explicit TypeValidatorVisitor(ScopeLayer * root);
  ~TypeValidatorVisitor() = default;

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
  void visit(DeclarationStatement * statement) override;

  void visit(IdentifierAssignStatement * statement) override;
  void visit(ArrayAssignStatement * statement) override;

  void visit(ArrayType * type) override;
  void visit(SimpleType * type) override;

  void visit(Declaration * declaration) override;

private:
  ScopeLayer * root_;
  ScopeLayer * current_layer_;

  std::stack<size_t> current_child_number_;

  void begin_scope_();
  void end_scope_();
};