#include "NewArrayExpression.hpp"

NewArrayExpression::NewArrayExpression(SimpleType * type, Expression * expr)
  : type_(type)
  , expression_(expr)
{}

NewArrayExpression::~NewArrayExpression() {
  delete type_;
  delete expression_;
}