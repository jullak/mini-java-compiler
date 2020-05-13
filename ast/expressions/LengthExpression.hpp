#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class LengthExpression : public Expression {
public:
  LengthExpression(Expression * l);
  ~LengthExpression() override;

private:
  Expression * left_;
};