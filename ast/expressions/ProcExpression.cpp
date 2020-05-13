#include "ProcExpression.hpp"

ProcExpression::ProcExpression(Expression * l, Expression * r)
  : left_(l)
  , right_(r)
{}

ProcExpression::~ProcExpression() {
  delete left_;
  delete right_;
}