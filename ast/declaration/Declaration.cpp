#include "Declaration.hpp"

Declaration::Declaration(Type * type, const std::string & ident)
  : type_(type)
  , identifier_(ident)
{}

Declaration::~Declaration() {
  delete type_;
}

void Declaration::accept(Visitor *visitor) {
  visitor->visit(this);
}