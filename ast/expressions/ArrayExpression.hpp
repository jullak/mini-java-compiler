#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class ArrayExpression : public Expression {
public:
  ArrayExpression(Expression * l, Expression * i);
  ~ArrayExpression() override;

  void accept(Visitor * visitor) override;

  Expression * left_;
  Expression * index_;
};