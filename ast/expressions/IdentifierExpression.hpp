#pragma once

#include <string>

#include "ASTElement.hpp"
#include "Expression.hpp"

class IdentifierExpression : public Expression {
public:
  IdentifierExpression(const std::string& ident);

private:
  std::string identifier_;
};