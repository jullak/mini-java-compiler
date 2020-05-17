#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"
#include "Statement.hpp"

class AssertStatement : public Statement {
public:
  explicit AssertStatement(Expression * checked);
  ~AssertStatement();

  void accept(Visitor * visitor) override;

  Expression * checked_;
};