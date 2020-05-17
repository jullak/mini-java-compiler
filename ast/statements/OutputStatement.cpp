#include "OutputStatement.hpp"

OutputStatement::OutputStatement(Expression * information)
  : information_(information)
{}

OutputStatement::~OutputStatement() {
  delete information_;
}

void OutputStatement::accept(Visitor *visitor) {
  visitor->visit(this);
}
