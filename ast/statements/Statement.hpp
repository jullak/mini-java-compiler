#pragma once

#include "ASTElement.hpp"

class Statement : public virtual ASTElement {
public:
  virtual ~Statement() {};
};
