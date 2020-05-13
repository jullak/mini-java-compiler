#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class OrExpression : public Expression {
public:
  OrExpression(Expression * l, Expression * r);
  ~OrExpression() override;

private:
  Expression * left_;
  Expression * right_;
};