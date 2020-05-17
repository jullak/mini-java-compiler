#include "Program.hpp"

Program::Program(StatementsList * statements)
  : statements_(statements)
{}

Program::~Program() {
  delete statements_;
}

void Program::visit_all(Visitor *visitor) {
  visitor->visit(statements_);
}