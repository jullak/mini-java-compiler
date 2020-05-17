#include "StatementsList.hpp"

StatementsList::StatementsList() {
  statements_.reserve(8);
}

StatementsList::~StatementsList() {
  for (auto st : statements_) {
    delete st;
  }
}

void StatementsList::add_statement(Statement *statement) {
  statements_.emplace_back(statement);
}

void StatementsList::accept(Visitor *visitor) {
  visitor->visit(this);
}