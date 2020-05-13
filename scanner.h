#pragma once

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL yy::parser::symbol_type Scanner::scan_token()

#include "parser.hh"

class Driver;

class Scanner : public yyFlexLexer {
public:
  Scanner(Driver & driver) :
    driver_(driver)
  {}

  virtual ~Scanner() {}
  virtual yy::parser::symbol_type scan_token();

protected:
  Driver & driver_;
};
