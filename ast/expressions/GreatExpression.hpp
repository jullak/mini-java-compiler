#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class GreatExpression : public Expression {
public:
  GreatExpression(Expression * l, Expression * r);
  ~GreatExpression() override;

  void accept(Visitor * visitor) override;

  Expression * left_;
  Expression * right_;
};