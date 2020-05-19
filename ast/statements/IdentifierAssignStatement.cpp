#include "IdentifierAssignStatement.hpp"

IdentifierAssignStatement::IdentifierAssignStatement(const std::string & ident, Expression * rvalue)
  : identifier_(ident)
  , rvalue_(rvalue)
{}

IdentifierAssignStatement::~IdentifierAssignStatement() {
  delete rvalue_;
}

void IdentifierAssignStatement::accept(Visitor *visitor) {
  visitor->visit(this);
}