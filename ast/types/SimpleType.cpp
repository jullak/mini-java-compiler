#include "SimpleType.hpp"

SimpleType::SimpleType(const std::string& type) {
  if (type == "int") {
    simple_type_ = INT;
  } else if (type == "bool") {
    simple_type_ = BOOL;
  }
}
