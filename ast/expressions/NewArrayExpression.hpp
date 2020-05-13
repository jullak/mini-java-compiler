#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"
#include "SimpleType.hpp"

class NewArrayExpression : public Expression {
public:
  NewArrayExpression(SimpleType * type, Expression * expr);
  ~NewArrayExpression() override;

private:
  SimpleType * type_;
  Expression * expression_;
};