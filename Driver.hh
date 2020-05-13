#pragma once

#include <fstream>
#include <string>

#include "parser.hh"
#include "Program.hpp"
#include "scanner.h"

class Driver {
public:
  friend class Scanner;

  Driver();

  void scan_begin();
  void scan_end();
  int parse(const std::string & file_name);

  void set_program(Program * program);
private:
  Scanner scanner_;
  yy::parser parser_;
  Program * program_;

  std::string file_name_;
  std::ifstream stream_;

  yy::location location_;
};