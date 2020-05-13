#include "StatementsList.hpp"

StatementsList::StatementsList() = default;

StatementsList::~StatementsList() {
  for (auto st : statements_) {
    delete st;
  }
}

void StatementsList::add_statement(Statement *statement) {
  statements_.push_back(statement);
}