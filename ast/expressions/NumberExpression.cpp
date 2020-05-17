#include "NumberExpression.hpp"

NumberExpression::NumberExpression(int num)
  : number_(num)
{}

void NumberExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}