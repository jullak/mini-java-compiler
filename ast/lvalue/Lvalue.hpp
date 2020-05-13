#pragma once

#include "ASTElement.hpp"

class Lvalue : public virtual ASTElement {
public:
  virtual ~Lvalue() {};
};
