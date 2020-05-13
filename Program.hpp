#pragma once

#include "StatementsList.hpp"

class Program {
public:
  Program(StatementsList * statements);
  ~Program();
private:
  StatementsList * statements_;
};