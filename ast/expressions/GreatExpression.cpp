#include "GreatExpression.hpp"

GreatExpression::GreatExpression(Expression * l, Expression * r)
  : left_(l)
  , right_(r)
{}

GreatExpression::~GreatExpression() {
  delete left_;
  delete right_;
}

void GreatExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}