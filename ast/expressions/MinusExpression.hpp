#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class MinusExpression : public Expression {
public:
  MinusExpression(Expression * l, Expression * r);
  ~MinusExpression() override;

private:
  Expression * left_;
  Expression * right_;
};