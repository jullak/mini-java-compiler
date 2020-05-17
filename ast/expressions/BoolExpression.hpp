#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class BoolExpression : public Expression {
public:
  explicit BoolExpression(bool boolean);

  void accept(Visitor * visitor) override;

  bool boolean_;
};