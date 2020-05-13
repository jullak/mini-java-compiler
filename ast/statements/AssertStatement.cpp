#include "AssertStatement.hpp"

AssertStatement::AssertStatement(Expression * checked)
  : checked_(checked)
{}

AssertStatement::~AssertStatement() {
  delete checked_;
}
