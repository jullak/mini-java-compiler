#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class ProcExpression : public Expression {
public:
  ProcExpression(Expression * l, Expression * r);
  ~ProcExpression();

  void accept(Visitor * visitor) override;

  Expression * left_;
  Expression * right_;
};