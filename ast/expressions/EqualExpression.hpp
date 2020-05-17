#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class EqualExpression : public Expression {
public:
  EqualExpression(Expression * l, Expression * r);
  ~EqualExpression() override;

  void accept(Visitor * visitor) override;

  Expression * left_;
  Expression * right_;
};