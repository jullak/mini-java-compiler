#pragma once

#include "ASTElement.hpp"
#include "Visitor.hpp"
#include "ScopeLayer.hpp"
#include "StatementsList.hpp"

class Program {
public:
  explicit Program(StatementsList * statements);
  ~Program();

  void visit_all(Visitor * visitor);
  ScopeLayer * get_scopes();
private:
  StatementsList * statements_;
  ScopeLayer root_;
};