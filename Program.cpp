#include "Program.hpp"

Program::Program(StatementsList * statements)
  : statements_(statements_)
{}

Program::~Program() {
  delete statements_;
}