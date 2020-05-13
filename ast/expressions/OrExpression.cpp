#include "OrExpression.hpp"

OrExpression::OrExpression(Expression * l, Expression * r)
  : left_(l)
  , right_(r)
{}

OrExpression::~OrExpression() {
  delete left_;
  delete right_;
}