#include "BraceStatement.hpp"

BraceStatement::BraceStatement(StatementsList * statements)
  : statements_(statements)
{}

BraceStatement::~BraceStatement() {
  delete statements_;
}

void BraceStatement::accept(Visitor *visitor) {
  visitor->visit(this);
}
