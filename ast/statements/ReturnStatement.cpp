#include "ReturnStatement.hpp"

ReturnStatement::ReturnStatement(Expression * ret)
  : returned_(ret)
{}

ReturnStatement::~ReturnStatement() {
  delete returned_;
}
