#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class PlusExpression : public Expression {
public:
  PlusExpression(Expression * l, Expression * r);
  ~PlusExpression() override;

private:
  Expression * left_;
  Expression * right_;
};