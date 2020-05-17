#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"
#include "Statement.hpp"

class OutputStatement : public Statement {
public:
  explicit OutputStatement(Expression * information);
  ~OutputStatement();

  void accept(Visitor * visitor) override;

  Expression * information_;
};