#include "ParenExpression.hpp"

ParenExpression::ParenExpression(Expression * expr)
  : expression_(expr)
{}

ParenExpression::~ParenExpression() {
  delete expression_;
}