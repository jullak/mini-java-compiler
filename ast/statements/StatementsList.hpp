#pragma once

#include <vector>

#include "ASTElement.hpp"
#include "Statement.hpp"

class StatementsList : public ASTElement {
public:
  StatementsList();
  ~StatementsList();

  void add_statement(Statement * statement);
  void accept(Visitor * visitor) override;

  std::vector<Statement *> statements_;
};