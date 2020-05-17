#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class MinusExpression : public Expression {
public:
  MinusExpression(Expression * l, Expression * r);
  ~MinusExpression() override;

  void accept(Visitor * visitor) override;

  Expression * left_;
  Expression * right_;
};