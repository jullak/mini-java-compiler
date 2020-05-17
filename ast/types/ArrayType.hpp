#pragma once

#include "ASTElement.hpp"
#include "Type.hpp"
#include "SimpleType.hpp"

class ArrayType : public Type {
public:
  explicit ArrayType(SimpleType * type);
  ~ArrayType() override;

  void accept(Visitor * visitor) override;

  SimpleType * array_type_;
};