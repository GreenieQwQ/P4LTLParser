

%option noyywrap

%x PREDICATE

%{
  #include <iostream>
  #include <cstdio>
  #include <cstring>
  #include "y.tab.h"
  int parens = 0;

  void echoToken(const char* yytext);
%}

LineTerminator \r|\n|\r\n
ws {LineTerminator}|[ \t\f]

Identifier [_a-zA-Z~][a-zA-Z0-9_~#\.]*
Header [_a-zA-Z~][a-zA-Z0-9_~#\.]*
DecIntegerLiteral 0|[1-9][0-9]*
HexIntegerLiteral [0][xX][0-9a-fA-F]+

%%
<INITIAL>"("					{echoToken(yytext); return LPAR; }
<INITIAL>")"					{echoToken(yytext); return RPAR; }

<INITIAL>"AP"				{echoToken(yytext); BEGIN(PREDICATE); return AP; }

<INITIAL>"[]"				{echoToken(yytext); return ALWAYS; }
<INITIAL>"<>"				{echoToken(yytext); return EVENTUALLY; }
<INITIAL>"U"					{echoToken(yytext); return UNTIL; }
<INITIAL>"W"					{echoToken(yytext); return WEAKUNTIL; }
<INITIAL>"R"					{echoToken(yytext); return RELEASE; }
<INITIAL>"&&"				{echoToken(yytext); return AND; }
<INITIAL>"||"				{echoToken(yytext); return OR; }
<INITIAL>"==>"				{echoToken(yytext); return IMPLIES; }
<INITIAL>"X"					{echoToken(yytext); return NEXT; }
<INITIAL>"!"					{echoToken(yytext); return NEG; }

<INITIAL>{ws}    			{/* ignore */ }
<INITIAL>{Identifier}    	{echoToken(yytext); yylval.str = strdup(yytext); return NAME; }

<PREDICATE>"("						{echoToken(yytext); parens++; return LPAR; }
<PREDICATE>"=="					{echoToken(yytext); return EQ; }
<PREDICATE>"<="					{echoToken(yytext); return LEQ; }
<PREDICATE>">="					{echoToken(yytext); return GEQ; }
<PREDICATE>">"						{echoToken(yytext); return GT; }
<PREDICATE>"<"						{echoToken(yytext); return LT; }
<PREDICATE>"!="					{echoToken(yytext); return NEQ; }
<PREDICATE>")"						{echoToken(yytext); parens--; if(parens == 0) { BEGIN(INITIAL); } return RPAR; }
<PREDICATE>","						{echoToken(yytext); return COMMA; }
<PREDICATE>"old"					{echoToken(yytext); return OLD; }
<PREDICATE>"Key"					{echoToken(yytext); return KEY; }
<PREDICATE>"+"						{echoToken(yytext); return PLUS; }
<PREDICATE>"-"						{echoToken(yytext); return MINUS; }
<PREDICATE>"*"						{echoToken(yytext); return MULTIPLY; }
<PREDICATE>"!"						{echoToken(yytext); return NEG; }
<PREDICATE>"&&"					{echoToken(yytext); return AND; }
<PREDICATE>"||"					{echoToken(yytext); return OR; }
<PREDICATE>"==>"					{echoToken(yytext); return IMPLIES; }
<PREDICATE>"true"					{echoToken(yytext); return TRUE; }
<PREDICATE>"false"					{echoToken(yytext); return FALSE; }
<PREDICATE>"fwd"					{echoToken(yytext); return FWD; }
<PREDICATE>"drop"					{echoToken(yytext); return DROP; }
<PREDICATE>"valid"					{echoToken(yytext); return VALID; }
<PREDICATE>"apply"					{echoToken(yytext); return APPLY; }
<PREDICATE>"["						{echoToken(yytext); return LBRACKET; }
<PREDICATE>"]"						{echoToken(yytext); return RBRACKET; }

<PREDICATE>{ws}    				{/* ignore */ }
<PREDICATE>{Header}	    		{echoToken(yytext); yylval.str = strdup(yytext); return NAME; }
<PREDICATE>{HexIntegerLiteral}		{echoToken(yytext); yylval.integer = std::strtol(yytext, nullptr, 16); return INT; }
<PREDICATE>{DecIntegerLiteral}		{echoToken(yytext); yylval.integer = std::strtol(yytext, nullptr, 10); return INT; }

 
<<EOF>>                 {echoToken(yytext); return EOF; }

%%

void echoToken(const char* yytext)
{
  std::cout << "Token: " << yytext << std::endl;
}