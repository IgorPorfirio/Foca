%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]
OPERADOR [+\-*/]
RELACIONAL (<=|>=|==|!=|<|>)
DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
ID {LETRA}({LETRA}|{NUM})*
BOOLEAN "TRUE"|"FALSE"
%%

"\n"		{}

{DELIM} 	{}

"="         {return *yytext; }


"main"		{return TK_MAIN;}

"int"		{yylval.tipo = "int"; yylval.traducao = yytext; return TK_TIPO;}
"float"     {yylval.tipo = "float"; yylval.traducao = yytext; return TK_TIPO;}
"bool"      {yylval.tipo = "bool"; yylval.traducao = yytext; return TK_TIPO;}
"char"      {yylval.tipo = "char"; yylval.traducao = yytext; return TK_TIPO;}

[(){}[\];,]	{ return *yytext; }


"||"        { yylval.label = yytext; return TK_LOGICO; }
"&&"        { yylval.label = yytext; return TK_LOGICO; }
{OPERADOR}		{ yylval.label = yytext; return TK_OP; }
{RELACIONAL}    { yylval.label = yytext; return TK_RELACIONAL; }
{NUM}		{ yylval.tipo = "int"; yylval.traducao = yytext; return TK_NUM; }
{REAL}      { yylval.tipo = "float"; yylval.traducao = yytext; return TK_REAL; }
{BOOLEAN}   { yylval.tipo = "bool"; yylval.traducao = yytext; return TK_BOOL; }
{CHAR}      { yylval.tipo = "char"; yylval.traducao = yytext; return TK_CHAR; }

{ID}		{ yylval.label = yytext; return TK_ID; }
.			{ *yytext; }

%%
