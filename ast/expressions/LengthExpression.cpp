#include "LengthExpression.hpp"

LengthExpression::LengthExpression(Expression * l)
  : left_(l)
{}

LengthExpression::~LengthExpression() {
  delete left_;
}