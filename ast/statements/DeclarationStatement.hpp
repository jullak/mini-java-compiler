#pragma once

#include "ASTElement.hpp"
#include "Statement.hpp"
#include "Declaration.hpp"

class DeclarationStatement : public Statement {
public:
  explicit DeclarationStatement(Declaration * decl);
  ~DeclarationStatement() override;

  void accept(Visitor * visitor) override;

  Declaration * declaration_;
};