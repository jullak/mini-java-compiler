#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"
#include "Lvalue.hpp"
#include "Statement.hpp"

class AssignStatement : public Statement {
public:
  AssignStatement(Lvalue * lv, Expression * rv);
  ~AssignStatement();
private:
  Lvalue * lvalue_;
  Expression * rvalue_;
};