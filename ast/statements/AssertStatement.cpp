#include "AssertStatement.hpp"

AssertStatement::AssertStatement(Expression * checked)
  : checked_(checked)
{}

AssertStatement::~AssertStatement() {
  delete checked_;
}

void AssertStatement::accept(Visitor *visitor){
  visitor->visit(this);
}