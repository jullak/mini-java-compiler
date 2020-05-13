#include "AndExpression.hpp"

AndExpression::AndExpression(Expression * l, Expression * r)
  : left_(l)
  , right_(r)
{}

AndExpression::~AndExpression() {
  delete left_;
  delete right_;
}