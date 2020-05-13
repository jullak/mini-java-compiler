#pragma once

#include <string>

#include "ASTElement.hpp"
#include "Lvalue.hpp"

class IdentifierLvalue : public Lvalue {
public:
  IdentifierLvalue(const std::string & ident);
private:
  std::string identifier_;
};