#include "PlusExpression.hpp"

PlusExpression::PlusExpression(Expression * l, Expression * r)
  : left_(l)
  , right_(r)
{}

PlusExpression::~PlusExpression() {
  delete left_;
  delete right_;
}