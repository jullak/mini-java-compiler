#include "OrExpression.hpp"

OrExpression::OrExpression(Expression * l, Expression * r)
  : left_(l)
  , right_(r)
{}

OrExpression::~OrExpression() {
  delete left_;
  delete right_;
}

void OrExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}