#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class SlashExpression : public Expression {
public:
  SlashExpression(Expression * l, Expression * r);
  ~SlashExpression();

private:
  Expression * left_;
  Expression * right_;
};