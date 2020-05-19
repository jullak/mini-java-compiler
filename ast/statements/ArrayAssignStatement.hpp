#pragma once

#include <string>

#include "ASTElement.hpp"
#include "Expression.hpp"
#include "Statement.hpp"

class ArrayAssignStatement : public Statement {
public:
  ArrayAssignStatement(const std::string & ident, Expression * expression, Expression * rvalue);
  ~ArrayAssignStatement() override;

  void accept(Visitor * visitor) override;

  std::string identifier_;
  Expression * expression_;
  Expression * rvalue_;
};