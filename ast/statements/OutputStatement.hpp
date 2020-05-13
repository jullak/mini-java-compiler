#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"
#include "Statement.hpp"

class OutputStatement : public Statement {
public:
  OutputStatement(Expression * information);
  ~OutputStatement();
private:
  Expression * information_;
};