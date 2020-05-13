#include "ArrayType.hpp"

ArrayType::ArrayType(SimpleType * type)
  : array_type_(type)
{}

ArrayType::~ArrayType() {
  delete array_type_;
}