#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class NumberExpression : public Expression {
public:
  NumberExpression(int num);

private:
  int number_;
};