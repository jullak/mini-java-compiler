#include "LengthExpression.hpp"

LengthExpression::LengthExpression(Expression * l)
  : left_(l)
{}

LengthExpression::~LengthExpression() {
  delete left_;
}

void LengthExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}