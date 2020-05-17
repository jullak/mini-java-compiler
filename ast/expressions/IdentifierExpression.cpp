#include "IdentifierExpression.hpp"

IdentifierExpression::IdentifierExpression(const std::string & ident)
  : identifier_(ident)
{}

void IdentifierExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}