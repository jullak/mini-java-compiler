#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"
#include "Statement.hpp"

class IfStatement : public Statement {
public:
  IfStatement(Expression * cond, Statement * statement);
  ~IfStatement();

  void accept(Visitor * visitor) override;

  Expression * condition_;
  Statement * statement_;
};