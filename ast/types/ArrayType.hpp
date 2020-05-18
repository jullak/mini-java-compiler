#pragma once

#include "ASTElement.hpp"
#include "PrimitiveTypes.hpp"
#include "SimpleType.hpp"
#include "Type.hpp"

class ArrayType : public Type {
public:
  explicit ArrayType(SimpleType * type);

  void accept(Visitor * visitor) override;
};