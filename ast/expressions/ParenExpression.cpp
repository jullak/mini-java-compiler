#include "ParenExpression.hpp"

ParenExpression::ParenExpression(Expression * expr)
  : expression_(expr)
{}

ParenExpression::~ParenExpression() {
  delete expression_;
}

void ParenExpression::accept(Visitor *visitor) {
  visitor->visit(this);
}