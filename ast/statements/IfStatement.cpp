#include "IfStatement.hpp"

IfStatement::IfStatement(Expression * cond, Statement * statement)
  : condition_(cond)
  , statement_(statement)
{}

IfStatement::~IfStatement() {
  delete condition_;
  delete statement_;
}
