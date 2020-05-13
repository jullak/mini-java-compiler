#pragma once

#include <string>

#include "ASTElement.hpp"
#include "Type.hpp"

enum Types { INT, BOOL, VOID };

class SimpleType : public Type {
public:
  SimpleType(const std::string & type);
private:
  Types simple_type_;
};