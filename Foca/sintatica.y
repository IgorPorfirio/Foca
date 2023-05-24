%{
#include <iostream>
#include <string>
#include <sstream>

int label_i = 0;



#define YYSTYPE atributos

std::stringstream declarationList;

using namespace std;

struct atributos
{
	string label;
	string traducao;
	bool declared = false;
};
string printDeclaracoes();
int yylex(void);
void yyerror(string);
std::string gen_label()
{
	std::stringstream label;
    label << "temp" << label_i++;
    return label.str();
}
%}

%token TK_NUM
%token TK_MAIN TK_ID TK_TIPO_INT
%token TK_FIM TK_ERROR
%token TK_OP

%start S






%left '+' '-' 
%left '*' '/' 


%%



S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "\n/*Compilador FOCA*/\n\n";
				cout << "#include <iostream>\n#iCompilador>\n#include<stdio.h>\n\n";
				cout << "int main(void)\n{\n";
				cout << printDeclaracoes() <<"\n"; // Printa declarações de variaveis
				//cout << declarationList <<"\n";
    			cout << $5.traducao << "\n"; // Print a tradução do código
    			cout << "\treturn 0;\n}" << endl;
			}
			;

BLOCO		: '{' COMANDOS '}'
			{
				$$.traducao = $2.traducao;
			}
			;

COMANDOS	: COMANDO COMANDOS
			|
			;

COMANDO 	: E ';'
			
			| DECLARACAO ';'
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			; 

E 			: E TK_OP E //operaçẽs básicas
			{
				std::string label = gen_label();
				$$.label = label;
				$$.traducao = $1.traducao + $3.traducao + "\t" + label + " = " + $1.label +" "+ $2.label +" "+ $3.label + ";\n";
				
			}
			
			| TK_ID '=' E //atribuição
			{
				//std::string label = gen_label();
				$$.traducao = $3.traducao + "\t" + $1.label + " = " + $3.label + ";\n";
        		$$.label = $1.label; // Assign the label of the expression to the variable
				
				
			}

			| TK_NUM
			{
				std::string label = gen_label();
				$$.label = label;
				$$.traducao = "\t" + label + " = " + $1.traducao + ";\n";
			}
			
			| TK_ID
			{
				
				std::string label = gen_label();
				$$.label = label;
				//declarationList << "\tint" << label << ";";
				$$.traducao = "\t" + label + " = " + $1.label + ";\n"; 
			}
			
DECLARACAO	: TK_TIPO_INT TK_ID
			{
				std::string label = gen_label();
				$$.label = label;
				declarationList << "\t" << $1.traducao << " " << $2.label << ";\n";
				$$.traducao = "\t" + $1.traducao + " " + $2.label + ";\n";
				$$.declared = true;
			}
			| TK_TIPO_INT TK_ID '=' E
				{
				std::string label = gen_label();
				$$.label = label;
				declarationList << "\t" << $1.traducao << " " << $2.label << ";\n";
				$$.traducao = "\t" + $1.traducao + " " + $2.label + " = " + $4.traducao +";\n";
				$$.declared = true;
				}
			;

%%

#include "lex.yy.c"

int yyparse();

string printDeclaracoes()
{
	stringstream declaracoes; 
	int i = 0;
	for( i; i < label_i; i++){
		declaracoes << "\tint temp" << i <<";\n";
	 	}
	declaracoes << declarationList.str();
	
	//declaracoes << "\n";

	return declaracoes.str();
}

int main( int argc, char* argv[] )
{
	yyparse(); //retorna 0 se a gramatica é valida, e 1 para invalida

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}				
