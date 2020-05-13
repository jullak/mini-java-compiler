#include "WhileStatement.hpp"

WhileStatement::WhileStatement(Expression * cond, Statement * statement)
  : condition_(cond)
  , statement_(statement)
{}

WhileStatement::~WhileStatement() {
  delete condition_;
  delete statement_;
}
