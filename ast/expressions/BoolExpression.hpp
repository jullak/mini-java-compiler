#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class BoolExpression : public Expression {
public:
  BoolExpression(bool boolean);

private:
  bool boolean_;
};