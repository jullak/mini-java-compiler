%{
    #include <cerrno>
    #include <climits>
    #include <cstdlib>
    #include <cstring> // strerror
    #include <iostream>
    #include <string>
    #include "Driver.hh"
    #include "parser.hh"
%}

%option noyywrap nounput noinput batch debug

%option c++
%option yyclass="Scanner"


id    [a-zA-Z][a-zA-Z_0-9]*
int   [0-9]+
blank [ \t\r]

%{
  yy::parser::symbol_type make_NUMBER(
    const std::string &s,
    const yy::parser::location_type& loc
  );
%}
%{
  #define YY_USER_ACTION  loc.columns (yyleng);
%}
%%
%{
  yy::location& loc = driver_.location_;
  loc.step();
%}

{blank}+   loc.step ();
\n+        loc.lines (yyleng); loc.step ();

"-"        return yy::parser::make_MINUS  (loc);
"+"        return yy::parser::make_PLUS   (loc);
"*"        return yy::parser::make_STAR   (loc);
"/"        return yy::parser::make_SLASH  (loc);
"%"        return yy::parser::make_PROC   (loc);
"="        return yy::parser::make_ASSIGN (loc);
"&&"       return yy::parser::make_AND    (loc);
"||"       return yy::parser::make_OR     (loc);
"<"        return yy::parser::make_LESS   (loc);
">"        return yy::parser::make_GREAT  (loc);
"=="       return yy::parser::make_EQUAL  (loc);
"("        return yy::parser::make_LPAREN (loc);
")"        return yy::parser::make_RPAREN (loc);
"["        return yy::parser::make_LBRACK (loc);
"]"        return yy::parser::make_RBRACK (loc);
"{"        return yy::parser::make_LBRACE (loc);
"}"        return yy::parser::make_RBRACE (loc);
";"        return yy::parser::make_SEMICOL(loc);
"!"        return yy::parser::make_EXCLAM (loc);
","        return yy::parser::make_COMMA  (loc);
"."        return yy::parser::make_DOT    (loc);
"if"       return yy::parser::make_IF     (loc);
"else"     return yy::parser::make_ELSE   (loc);
"while"    return yy::parser::make_WHILE  (loc);
"return"   return yy::parser::make_RET    (loc);
"assert"   return yy::parser::make_ASSERT (loc);
"new"      return yy::parser::make_NEW    (loc);
"int"      return yy::parser::make_INT    (loc);
"boolean"  return yy::parser::make_BOOL   (loc);
"void"     return yy::parser::make_VOID   (loc);
"this"     return yy::parser::make_THIS   (loc);
"true"     return yy::parser::make_TRUE   (loc);
"false"    return yy::parser::make_FALSE  (loc);
"length"   return yy::parser::make_LEN    (loc);
"System.out.println"    return yy::parser::make_COUT    (loc);
"public static void main"   return yy::parser::make_PSVM(loc);
"class"    return yy::parser::make_CLASS  (loc);
{int}      return make_NUMBER(yytext, loc);
{id}       return yy::parser::make_IDENTIFIER(yytext, loc);
<<EOF>>    return yy::parser::make_END (loc);
%%

yy::parser::symbol_type make_NUMBER(
  const std::string &s,
  const yy::parser::location_type& loc
) {
  errno = 0;
  long n = strtol(s.c_str(), NULL, 10);
  if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
    throw yy::parser::syntax_error(loc, "integer is out of range: " + s);
  return yy::parser::make_NUMBER((int) n, loc);
}