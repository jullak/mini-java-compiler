#include "OutputStatement.hpp"

OutputStatement::OutputStatement(Expression * information)
  : information_(information)
{}

OutputStatement::~OutputStatement() {
  delete information_;
}
