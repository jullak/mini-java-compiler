#pragma once

#include <string>

#include "ASTElement.hpp"
#include "Expression.hpp"
#include "Lvalue.hpp"

class ElementLvalue : public Lvalue {
public:
  ElementLvalue(const std::string & ident, Expression * expression);
  ~ElementLvalue();
private:
  std::string identifier_;
  Expression * expression_;
};