#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class ParenExpression : public Expression {
public:
  ParenExpression(Expression * expr);
  ~ParenExpression() override;

private:
  Expression * expression_;
};