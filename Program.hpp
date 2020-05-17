#pragma once

#include "ASTElement.hpp"
#include "Visitor.hpp"
#include "StatementsList.hpp"

class Program {
public:
  explicit Program(StatementsList * statements);
  ~Program();

  void visit_all(Visitor * visitor);
private:
  StatementsList * statements_;
};