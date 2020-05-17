#include "EqualExpression.hpp"

EqualExpression::EqualExpression(Expression * l, Expression * r)
  : left_(l)
  , right_(r)
{}

EqualExpression::~EqualExpression() {
  delete left_;
  delete right_;
}

void EqualExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}