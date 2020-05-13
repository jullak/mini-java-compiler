#include "StarExpression.hpp"

StarExpression::StarExpression(Expression * l, Expression * r)
  : left_(l)
  , right_(r)
{}

StarExpression::~StarExpression() {
  delete left_;
  delete right_;
}