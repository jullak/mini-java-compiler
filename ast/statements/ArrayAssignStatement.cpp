#include "ArrayAssignStatement.hpp"

ArrayAssignStatement::ArrayAssignStatement(const std::string & ident, Expression * expression, Expression * rvalue)
  : identifier_(ident)
  , expression_(expression)
  , rvalue_(rvalue)
{}

ArrayAssignStatement::~ArrayAssignStatement() {
  delete expression_;
  delete rvalue_;
}

void ArrayAssignStatement::accept(Visitor *visitor) {
  visitor->visit(this);
}