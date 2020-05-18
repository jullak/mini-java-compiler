#include "SimpleType.hpp"

SimpleType::SimpleType(const std::string& type) {
  if (type == "int") {
    type_ = INT;
  } else if (type == "bool") {
    type_ = BOOL;
  }
}

void SimpleType::accept(Visitor *visitor) {
  visitor->visit(this);
}
