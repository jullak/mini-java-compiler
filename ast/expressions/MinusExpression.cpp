#include "MinusExpression.hpp"

MinusExpression::MinusExpression(Expression * l, Expression * r)
  : left_(l)
  , right_(r)
{}

MinusExpression::~MinusExpression() {
  delete left_;
  delete right_;
}

void MinusExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}