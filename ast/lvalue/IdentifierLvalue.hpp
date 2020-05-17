#pragma once

#include <string>

#include "ASTElement.hpp"
#include "Lvalue.hpp"

class IdentifierLvalue : public Lvalue {
public:
  explicit IdentifierLvalue(const std::string & ident);

  void accept(Visitor * visitor) override;

  std::string identifier_;
};