#include "Driver.hh"
#include "parser.hh"
#include "PrintVisitor.hpp"
#include "TypeValidatorVisitor.hpp"
#include "ScopeBuilderVisitor.hpp"

Driver::Driver()
  : scanner_(*this)
  , parser_(scanner_, *this)
{}

int Driver::parse(const std::string & file_name) {
  file_name_ = file_name;
  location_.initialize(&file_name_);

  scan_begin();
  int res = parser_();

  scan_end();
  return res;
}

void Driver::scan_begin() {
  if (file_name_.empty() || file_name_ == "-") {}
  else {
    stream_.open(file_name_);
    scanner_.yyrestart(&stream_);
  }
}

void Driver::scan_end() {
  stream_.close();
}

void Driver::set_program(Program * program) {
  program_ = program;
}

void Driver::print_ast_tree() {
  PrintVisitor printer("tree.txt");

  program_->visit_all(&printer);
}

void Driver::build_scope() {
  ScopeBuilderVisitor scope_builder(program_->get_scopes());

  program_->visit_all(&scope_builder);
}

void Driver::check_type() {
  TypeValidatorVisitor type_validator(program_->get_scopes());

  program_->visit_all(&type_validator);
}