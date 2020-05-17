#include "DeclarationStatement.hpp"

DeclarationStatement::DeclarationStatement(Declaration * decl)
  : declaration_(decl)
{}

DeclarationStatement::~DeclarationStatement() {
  delete declaration_;
}

void DeclarationStatement::accept(Visitor *visitor) {
  visitor->visit(this);
}