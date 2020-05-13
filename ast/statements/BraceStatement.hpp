#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"
#include "Statement.hpp"
#include "StatementsList.hpp"

class BraceStatement : public Statement {
public:
  BraceStatement(StatementsList * statements);
  ~BraceStatement();
private:
  StatementsList * statements_;
};