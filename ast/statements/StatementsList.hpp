#pragma once

#include <vector>

#include "Statement.hpp"

class StatementsList {
public:
  StatementsList();
  ~StatementsList();

  void add_statement(Statement * statement);
private:
  std::vector<Statement *> statements_;
};