#pragma once

#include "ASTElement.hpp"
#include "PrimitiveTypes.hpp"

class Type : public ASTElement {
public:
  virtual ~Type() {}

  PrimitiveTypes type_;
};