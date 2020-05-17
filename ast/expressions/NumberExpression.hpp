#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class NumberExpression : public Expression {
public:
  explicit NumberExpression(int num);

  void accept(Visitor * visitor) override;

  int number_;
};