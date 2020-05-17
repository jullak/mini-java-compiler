#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"

class ParenExpression : public Expression {
public:
  explicit ParenExpression(Expression * expr);
  ~ParenExpression() override;

  void accept(Visitor * visitor) override;

  Expression * expression_;
};