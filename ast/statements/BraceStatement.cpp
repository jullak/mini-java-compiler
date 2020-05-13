#include "BraceStatement.hpp"

BraceStatement::BraceStatement(StatementsList * statements)
  : statements_(statements)
{}

BraceStatement::~BraceStatement() {
  delete statements_;
}
