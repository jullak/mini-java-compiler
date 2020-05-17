#include "ReturnStatement.hpp"

ReturnStatement::ReturnStatement(Expression * ret)
  : returned_(ret)
{}

ReturnStatement::~ReturnStatement() {
  delete returned_;
}

void ReturnStatement::accept(Visitor *visitor) {
  visitor->visit(this);
}
