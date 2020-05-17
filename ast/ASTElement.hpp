#pragma once

#include "Visitor.hpp"

class ASTElement {
public:
  virtual void accept(Visitor * visitor) = 0;
  virtual ~ASTElement() {}
};
