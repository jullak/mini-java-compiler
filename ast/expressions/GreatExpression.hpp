#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class GreatExpression : public Expression {
public:
  GreatExpression(Expression * l, Expression * r);
  ~GreatExpression() override;

private:
  Expression * left_;
  Expression * right_;
};