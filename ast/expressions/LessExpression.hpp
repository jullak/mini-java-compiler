#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class LessExpression : public Expression {
public:
  LessExpression(Expression * l, Expression * r);
  ~LessExpression() override;

  void accept(Visitor * visitor) override;

  Expression * left_;
  Expression * right_;
};