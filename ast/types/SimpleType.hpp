#pragma once

#include <string>

#include "ASTElement.hpp"
#include "Type.hpp"

enum Types { INT, BOOL, VOID };

class SimpleType : public Type {
public:
  explicit SimpleType(const std::string & type);

  void accept(Visitor * visitor) override;

  Types simple_type_;
};