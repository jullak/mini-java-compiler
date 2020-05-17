#pragma once

#include <string>

#include "ASTElement.hpp"
#include "Expression.hpp"

class IdentifierExpression : public Expression {
public:
  explicit IdentifierExpression(const std::string & ident);

  void accept(Visitor * visitor) override;

  std::string identifier_;
};