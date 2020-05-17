#include "ElementLvalue.hpp"

ElementLvalue::ElementLvalue(const std::string & ident, Expression * expression)
  : identifier_(ident)
  , expression_(expression)
{}

ElementLvalue::~ElementLvalue() {
  delete expression_;
}

void ElementLvalue::accept(Visitor *visitor) {
  visitor->visit(this);
}