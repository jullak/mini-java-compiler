#include "ArrayExpression.hpp"

ArrayExpression::ArrayExpression(Expression * l, Expression * i)
  : left_(l)
  , index_(i)
{}

ArrayExpression::~ArrayExpression() {
  delete left_;
  delete index_;
}

void ArrayExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}