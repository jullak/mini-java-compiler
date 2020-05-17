#include "NotExpression.hpp"

NotExpression::NotExpression(Expression * l)
  : left_(l)
{}

NotExpression::~NotExpression() {
  delete left_;
}

void NotExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}