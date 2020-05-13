#pragma once

#include "ASTElement.hpp"
#include "Statement.hpp"
#include "Declaration.hpp"

class DeclarationStatement : public Statement {
public:
  DeclarationStatement(Declaration * decl);
  ~DeclarationStatement() override;

private:
  Declaration * declaration_;
};