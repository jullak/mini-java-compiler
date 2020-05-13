#include "IfElseStatement.hpp"

IfElseStatement::IfElseStatement(Expression * cond, Statement * st1, Statement * st2)
  : condition_(cond)
  , statementIf_(st1)
  , statementElse_(st2)
{}

IfElseStatement::~IfElseStatement() {
  delete condition_;
  delete statementIf_;
  delete statementElse_;
}
