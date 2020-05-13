#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class UnaryMinusExpression : public Expression {
public:
  UnaryMinusExpression(Expression * expr);
  ~UnaryMinusExpression() override;

private:
  Expression * expression_;
};