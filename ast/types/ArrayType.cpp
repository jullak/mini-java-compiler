#include "ArrayType.hpp"

ArrayType::ArrayType(SimpleType * type) {
  if (type->type_ == INT) {
    type_ = INT_ARRAY;
  } else if (type->type_ == BOOL) {
    type_ = BOOL_ARRAY;
  }
}

void ArrayType::accept(Visitor *visitor) {
  visitor->visit(this);
}