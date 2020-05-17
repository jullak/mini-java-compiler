#pragma once

#include "ASTElement.hpp"
#include "Expression.hpp"
#include "Statement.hpp"

class ReturnStatement : public Statement {
public:
  explicit ReturnStatement(Expression * ret);
  ~ReturnStatement();

  void accept(Visitor * visitor) override;

  Expression * returned_;
};