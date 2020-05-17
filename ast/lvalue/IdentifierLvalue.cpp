#include "IdentifierLvalue.hpp"

IdentifierLvalue::IdentifierLvalue(const std::string & ident)
  : identifier_(ident)
{}

void IdentifierLvalue::accept(Visitor *visitor) {
  visitor->visit(this);
}