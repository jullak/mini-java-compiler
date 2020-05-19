#pragma once

#include <string>

#include "ASTElement.hpp"
#include "Expression.hpp"
#include "Statement.hpp"

class IdentifierAssignStatement : public Statement {
public:
  IdentifierAssignStatement(const std::string & ident, Expression * rvalue);
  ~IdentifierAssignStatement() override;

  void accept(Visitor * visitor) override;

  std::string identifier_;
  Expression * rvalue_;
};