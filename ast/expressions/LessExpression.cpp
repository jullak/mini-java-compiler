#include "LessExpression.hpp"

LessExpression::LessExpression(Expression * l, Expression * r)
  : left_(l)
  , right_(r)
{}

LessExpression::~LessExpression() {
  delete left_;
  delete right_;
}

void LessExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}