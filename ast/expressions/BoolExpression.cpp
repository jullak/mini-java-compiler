#include "BoolExpression.hpp"

BoolExpression::BoolExpression(bool boolean)
  : boolean_(boolean)
{}

void BoolExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}
