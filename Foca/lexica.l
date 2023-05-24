%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]
OPERADOR [+\-*/]
DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
ID {LETRA}({LETRA}|{NUM})*

%%

"\n"		{}

{DELIM} 	{}

"="         {return *yytext; }
"main"		{return TK_MAIN;}

"int"		{yylval.traducao = yytext; return TK_TIPO_INT;}

[(){}[\];,]	{ return *yytext; }


{OPERADOR}		{ yylval.label = yytext; return TK_OP; }
{NUM}		{ yylval.traducao = yytext; return TK_NUM; }
{ID}		{ yylval.label = yytext; return TK_ID; }

.			{ *yytext; }

%%
