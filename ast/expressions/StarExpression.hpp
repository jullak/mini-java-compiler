#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class StarExpression : public Expression {
public:
  StarExpression(Expression * l, Expression * r);
  ~StarExpression();

private:
  Expression * left_;
  Expression * right_;
};