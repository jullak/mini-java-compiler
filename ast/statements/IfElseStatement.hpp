#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"
#include "Statement.hpp"

class IfElseStatement : public Statement {
public:
  IfElseStatement(Expression * cond, Statement * st1, Statement * st2);
  ~IfElseStatement();

  void accept(Visitor * visitor) override;

  Expression * condition_;
  Statement * statementIf_;
  Statement * statementElse_;
};