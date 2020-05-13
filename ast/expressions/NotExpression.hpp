#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class NotExpression : public Expression {
public:
  NotExpression(Expression * l);
  ~NotExpression() override;

private:
  Expression * left_;
};