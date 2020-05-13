#pragma once

#include "ASTElement.hpp"
#include "Type.hpp"
#include "SimpleType.hpp"

class ArrayType : public Type {
public:
  ArrayType(SimpleType * type);
  ~ArrayType() override;
private:
  SimpleType * array_type_;
};