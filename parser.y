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

    #include "ForwardDeclaration.hpp"
}

%code {
    #include "Driver.hh"
    #include "location.hh"

    #include "Elements.hpp"

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

statement:
    "assert" "(" expr ")" {$$ = new AssertStatement($3);} |
    local_var_declaration ";" {$$ = new DeclarationStatement($1);} |
    "{" statements "}" {$$ = new BraceStatement($2);} |
    "if" "(" expr ")" statement {$$ = new IfStatement($3, $5);} |
    "if" "(" expr ")" statement "else" statement {$$ = new IfElseStatement($3, $5, $7);} |
    "while" "(" expr ")" statement {$$ = new WhileStatement($3, $5);} |
    COUT "(" expr ")" ";" {$$ = new OutputStatement($3);} |
    "identifier" "=" expr ";" {$$ = new IdentifierAssignStatement($1, $3);} |
    "identifier" "[" expr "]" "=" expr ";" {$$ = new ArrayAssignStatement($1, $3, $6);} |
    "return" expr ";" {$$ = new ReturnStatement($2);} ;

statements:
    %empty {$$ = new StatementsList(); } |
    statements statement { $1->add_statement($2); $$=$1; } ;

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