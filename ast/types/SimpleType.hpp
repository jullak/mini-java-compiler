#pragma once

#include <string>

#include "ASTElement.hpp"
#include "PrimitiveTypes.hpp"
#include "Type.hpp"

class SimpleType : public Type {
public:
  explicit SimpleType(const std::string & type);

  void accept(Visitor * visitor) override;
};