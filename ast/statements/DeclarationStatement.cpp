#include "DeclarationStatement.hpp"

DeclarationStatement::DeclarationStatement(Declaration * decl)
  : declaration_(decl)
{}

DeclarationStatement::~DeclarationStatement() {
  delete declaration_;
}