#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"
#include "Statement.hpp"

class ReturnStatement : public Statement {
public:
  ReturnStatement(Expression * ret);
  ~ReturnStatement();
private:
  Expression * returned_;
};