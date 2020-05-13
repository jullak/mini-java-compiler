#include "SlashExpression.hpp"

SlashExpression::SlashExpression(Expression * l, Expression * r)
  : left_(l)
  , right_(r)
{}

SlashExpression::~SlashExpression() {
  delete left_;
  delete right_;
}