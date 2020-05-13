#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"
#include "Statement.hpp"

class AssertStatement : public Statement {
public:
  AssertStatement(Expression * checked);
  ~AssertStatement();
private:
  Expression * checked_;
};