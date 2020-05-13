#include "UnaryMinusExpression.hpp"

UnaryMinusExpression::UnaryMinusExpression(Expression * expr)
  : expression_(expr)
{}

UnaryMinusExpression::~UnaryMinusExpression() {
  delete expression_;
}