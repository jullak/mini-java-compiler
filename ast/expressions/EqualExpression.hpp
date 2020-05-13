#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class EqualExpression : public Expression {
public:
  EqualExpression(Expression * l, Expression * r);
  ~EqualExpression() override;

private:
  Expression * left_;
  Expression * right_;
};