#include "AssignStatement.hpp"

AssignStatement::AssignStatement(Lvalue * lv, Expression * rv)
  : lvalue_(lv)
  , rvalue_(rv)
{}

AssignStatement::~AssignStatement() {
  delete lvalue_;
  delete rvalue_;
}
