#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class LengthExpression : public Expression {
public:
  explicit LengthExpression(Expression * l);
  ~LengthExpression() override;

  void accept(Visitor * visitor) override;

  Expression * left_;
};