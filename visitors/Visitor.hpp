#pragma once

#include "../ForwardDeclaration.hpp"

class Visitor {
public:
  virtual ~Visitor() {}

  virtual void visit(PlusExpression * expression) = 0;
  virtual void visit(MinusExpression * expression) = 0;
  virtual void visit(StarExpression * expression) = 0;
  virtual void visit(SlashExpression * expression) = 0;
  virtual void visit(ProcExpression * expression) = 0;
  virtual void visit(AndExpression * expression) = 0;
  virtual void visit(OrExpression * expression) = 0;
  virtual void visit(LessExpression * expression) = 0;
  virtual void visit(GreatExpression * expression) = 0;
  virtual void visit(EqualExpression * expression) = 0;
  virtual void visit(ArrayExpression * expression) = 0;
  virtual void visit(LengthExpression * expression) = 0;
  virtual void visit(NewArrayExpression * expression) = 0;
  virtual void visit(NotExpression * expression) = 0;
  virtual void visit(NumberExpression * expression) = 0;
  virtual void visit(BoolExpression * expression) = 0;
  virtual void visit(IdentifierExpression * expression) = 0;
  virtual void visit(UnaryMinusExpression * expression) = 0;
  virtual void visit(ParenExpression * expression) = 0;

  virtual void visit(StatementsList * statement) = 0;
  virtual void visit(IfStatement * statement) = 0;
  virtual void visit(IfElseStatement * statement) = 0;
  virtual void visit(WhileStatement * statement) = 0;
  virtual void visit(ReturnStatement * statement) = 0;
  virtual void visit(AssertStatement * statement) = 0;
  virtual void visit(OutputStatement * statement) = 0;
  virtual void visit(BraceStatement * statement) = 0;
  virtual void visit(AssignStatement * statement) = 0;
  virtual void visit(DeclarationStatement * statement) = 0;

  virtual void visit(IdentifierLvalue * lvalue) = 0;
  virtual void visit(ElementLvalue * lvalue) = 0;

  virtual void visit(ArrayType * type) = 0;
  virtual void visit(SimpleType * type) = 0;

  virtual void visit(Declaration * declaration) = 0;
};