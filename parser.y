%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert
%define parse.trace
%define parse.error verbose

%code requires {
    #include <string>
    class Scanner;
    class Driver;

    class Program;

    class Expression;

    class PlusExpression;
    class MinusExpression;
    class StarExpression;
    class SlashExpression;
    class ProcExpression;
    class AndExpression;
    class OrExpression;
    class LessExpression;
    class GreatExpression;
    class EqualExpression;
    class ArrayExpression;
    class LengthExpression;
    class NewArrayExpression;
    class NotExpression;
    class NumberExpression;
    class BoolExpression;
    class IdentifierExpression;
    class UnaryMinusExpression;
    class ParenExpression;

    class Statement;
    class StatementsList;
    class IfStatement;
    class IfElseStatement;
    class WhileStatement;
    class ReturnStatement;
    class AssertStatement;
    class OutputStatement;
    class BraceStatement;
    class AssignStatement;
    class DeclarationStatement;

    class Lvalue;
    class IdentifierLvalue;
    class ElementLvalue;

    class Type;
    class ArrayType;
    class SimpleType;

    class Declaration;
}

%code {
    #include "Driver.hh"
    #include "location.hh"

    #include "Program.hpp"
    #include "ast/expressions/Expression.hpp"

    #include "ast/expressions/PlusExpression.hpp"
    #include "ast/expressions/MinusExpression.hpp"
    #include "ast/expressions/StarExpression.hpp"
    #include "ast/expressions/SlashExpression.hpp"
    #include "ast/expressions/ProcExpression.hpp"
    #include "ast/expressions/AndExpression.hpp"
    #include "ast/expressions/OrExpression.hpp"
    #include "ast/expressions/LessExpression.hpp"
    #include "ast/expressions/GreatExpression.hpp"
    #include "ast/expressions/EqualExpression.hpp"
    #include "ast/expressions/ArrayExpression.hpp"
    #include "ast/expressions/LengthExpression.hpp"
    #include "ast/expressions/NewArrayExpression.hpp"
    #include "ast/expressions/NotExpression.hpp"
    #include "ast/expressions/NumberExpression.hpp"
    #include "ast/expressions/BoolExpression.hpp"
    #include "ast/expressions/IdentifierExpression.hpp"
    #include "ast/expressions/UnaryMinusExpression.hpp"
    #include "ast/expressions/ParenExpression.hpp"


    #include "ast/statements/Statement.hpp"
    #include "ast/statements/StatementsList.hpp"
    #include "ast/statements/IfStatement.hpp"
    #include "ast/statements/IfElseStatement.hpp"
    #include "ast/statements/WhileStatement.hpp"
    #include "ast/statements/ReturnStatement.hpp"
    #include "ast/statements/AssertStatement.hpp"
    #include "ast/statements/OutputStatement.hpp"
    #include "ast/statements/BraceStatement.hpp"
    #include "ast/statements/AssignStatement.hpp"
    #include "ast/statements/DeclarationStatement.hpp"

    #include "ast/lvalue/Lvalue.hpp"
    #include "ast/lvalue/IdentifierLvalue.hpp"
    #include "ast/lvalue/ElementLvalue.hpp"

    #include "ast/types/Type.hpp"
    #include "ast/types/ArrayType.hpp"
    #include "ast/types/SimpleType.hpp"

    #include "ast/declaration/Declaration.hpp"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.scan_token();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    PROC "%"
    ASSIGN "="
    AND "&&"
    OR "||"
    LESS "<"
    GREAT ">"
    EQUAL "=="
    LPAREN "("
    RPAREN ")"
    LBRACK "["
    RBRACK "]"
    LBRACE "{"
    RBRACE "}"
    SEMICOL ";"
    EXCLAM "!"
    COMMA ","
    DOT "."
    IF "if"
    ELSE "else"
    WHILE "while"
    RET "return"
    ASSERT "assert"
    NEW "new"
    INT "int"
    BOOL "boolean"
    VOID "void"
    THIS "this"
    TRUE "true"
    FALSE "false"
    LEN "length"
    COUT "System.out.println"
    PSVM "public static void main"
    CLASS "class"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%nterm <Expression*> expr
%nterm <Statement*> statement
%nterm <StatementsList*> statements
%nterm <Lvalue*> lvalue
%nterm <ArrayType*> array_type
%nterm <SimpleType*> simple_type
%nterm <Type*> type
%nterm <Declaration*> var_declaration
%nterm <Declaration*> local_var_declaration
%nterm <Program*> main_class
%nterm <Program*> program

%%
%start program;

program: main_class { driver.set_program($1); };

main_class: "class" "identifier" "{" PSVM "(" ")" "{" statements "}" "}" { $$ = new Program($8); } ;

type:
    simple_type {$$ = $1;} |
    array_type {$$ = $1;} ;

simple_type:
    INT {$$ = new SimpleType("int");} |
    BOOL {$$ = new SimpleType("bool");} ;
//    VOID;

array_type: simple_type "[" "]" {$$ = new ArrayType($1);} ;

var_declaration: type "identifier" {$$ = new Declaration($1, $2);} ;

local_var_declaration: var_declaration {$$ = $1;} ;

lvalue:
    "identifier" {$$ = new IdentifierLvalue($1);} |
    "identifier" "[" expr "]" {$$ = new ElementLvalue($1, $3);} ;

statement:
    "assert" "(" expr ")" {$$ = new AssertStatement($3);} |
    local_var_declaration ";" {$$ = new DeclarationStatement($1);} |
    "{" statements "}" {$$ = new BraceStatement($2);} |
    "if" "(" expr ")" statement {$$ = new IfStatement($3, $5);} |
    "if" "(" expr ")" statement "else" statement {$$ = new IfElseStatement($3, $5, $7);} |
    "while" "(" expr ")" statement {$$ = new WhileStatement($3, $5);} |
    COUT "(" expr ")" ";" {$$ = new OutputStatement($3);} |
    lvalue "=" expr ";" {$$ = new AssignStatement($1, $3);} |
    "return" expr ";" {$$ = new ReturnStatement($2);} ;

statements:
    %empty {$$ = new StatementsList(); } |
    statements statement { $1->add_statement($2); } ;

%left "||";
%left "&&";
%left "!";
%left "<" ">" "==";
%left "+" "-";
%left "*" "/" "%";
%precedence NEG;

expr:
    expr "+" expr {$$ = new PlusExpression($1, $3);} |
    expr "-" expr {$$ = new MinusExpression($1, $3);} |
    expr "*" expr {$$ = new StarExpression($1, $3);} |
    expr "/" expr {$$ = new SlashExpression($1, $3);} |
    expr "%" expr {$$ = new ProcExpression($1, $3);} |
    expr "&&" expr {$$ = new AndExpression($1, $3);} |
    expr "||" expr {$$ = new OrExpression($1, $3);} |
    expr "<" expr {$$ = new LessExpression($1, $3);} |
    expr ">" expr {$$ = new GreatExpression($1, $3);} |
    expr "==" expr {$$ = new EqualExpression($1, $3);} |
    expr "[" expr "]" {$$ = new ArrayExpression($1, $3);} |
    expr "." "length" {$$ = new LengthExpression($1);} |
    "new" simple_type "[" expr "]" {$$ = new NewArrayExpression($2, $4);} |
    "!" expr {$$ = new NotExpression($2);} |
    "-" expr %prec NEG {$$ = new UnaryMinusExpression($2);} |
    "(" expr ")" {$$ = new ParenExpression($2);} |
    "identifier" {$$ = new IdentifierExpression($1);} |
//    "this" |
    "true" {$$ = new BoolExpression(true);} |
    "false" {$$ = new BoolExpression(false);} |
    "number" {$$ = new NumberExpression($1);} ;


%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}