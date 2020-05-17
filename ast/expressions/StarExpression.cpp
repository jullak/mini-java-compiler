#include "StarExpression.hpp"

StarExpression::StarExpression(Expression * l, Expression * r)
  : left_(l)
  , right_(r)
{}

StarExpression::~StarExpression() {
  delete left_;
  delete right_;
}

void StarExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}