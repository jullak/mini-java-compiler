#include "NotExpression.hpp"

NotExpression::NotExpression(Expression * l)
  : left_(l)
{}

NotExpression::~NotExpression() {
  delete left_;
}