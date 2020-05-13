#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"
#include "Statement.hpp"

class WhileStatement : public Statement {
public:
  WhileStatement(Expression * cond, Statement * statement);
  ~WhileStatement();
private:
  Expression * condition_;
  Statement * statement_;
};