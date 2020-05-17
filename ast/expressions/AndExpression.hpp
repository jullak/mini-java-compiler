#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class AndExpression : public Expression {
public:
  AndExpression(Expression * l, Expression * r);
  ~AndExpression() override;

  void accept(Visitor * visitor) override;

  Expression * left_;
  Expression * right_;
};