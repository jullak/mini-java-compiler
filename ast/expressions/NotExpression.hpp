#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class NotExpression : public Expression {
public:
  explicit NotExpression(Expression * l);
  ~NotExpression() override;

  void accept(Visitor * visitor) override;

  Expression * left_;
};