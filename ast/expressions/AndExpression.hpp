#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class AndExpression : public Expression {
public:
  AndExpression(Expression * l, Expression * r);
  ~AndExpression() override;

private:
  Expression * left_;
  Expression * right_;
};