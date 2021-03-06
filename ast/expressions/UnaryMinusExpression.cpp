#include "UnaryMinusExpression.hpp"

UnaryMinusExpression::UnaryMinusExpression(Expression * expr)
  : expression_(expr)
{}

UnaryMinusExpression::~UnaryMinusExpression() {
  delete expression_;
}

void UnaryMinusExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}