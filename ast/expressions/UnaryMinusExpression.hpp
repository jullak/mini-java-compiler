#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class UnaryMinusExpression : public Expression {
public:
  explicit UnaryMinusExpression(Expression * expr);
  ~UnaryMinusExpression() override;

  void accept(Visitor * visitor) override;

  Expression * expression_;
};