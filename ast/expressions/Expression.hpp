#pragma once

#include "ASTElement.hpp"

class Expression : public virtual ASTElement {
public:
  virtual ~Expression() {}
};
