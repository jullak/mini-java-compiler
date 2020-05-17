#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"
#include "Statement.hpp"
#include "StatementsList.hpp"

class BraceStatement : public Statement {
public:
  explicit BraceStatement(StatementsList * statements);
  ~BraceStatement();

  void accept(Visitor * visitor) override;

  StatementsList * statements_;
};