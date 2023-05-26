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
	string tipo;
};
string printDeclaracoes();
int yylex(void);
void yyerror(string);

std::string gen_label();

%}

%token TK_NUM
%token TK_REAL TK_TIPO
%token TK_MAIN TK_ID 
%token TK_FIM TK_ERROR
%token TK_OP

%start S






%left '+' '-' 
%left '*' '/' 


%%



S 			: TK_TIPO TK_MAIN '(' ')' BLOCO
			{
				if($1.tipo != "int")
				{
					cout << $2.label;
					yyerror(" main deve ser do tipo int");
				}
				cout << "\n/*Compilador FOCA*/\n\n";
				cout << "#include <iostream>\n#iCompilador>\n#include<stdio.h>\n\n";
				cout << "int main(void)\n{\n";
				cout << printDeclaracoes() <<"\n"; // Printa declarações de variaveis
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
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			|
			;

COMANDO 	: E ';'
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
			}
			| DECLARACAO ';'
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
			}
			; 

E 			: E TK_OP E //operaçẽs básicas 
			{	
				
				if($1.tipo != $3.tipo)
				{
					if($1.tipo == "float")
					{
						
						std::string label = gen_label();
						$3.tipo = $1.tipo;
						$3.traducao = $3.traducao +  "\t" + label + " = " + $1.tipo + " " + $3.label + ";\n";
						$3.label = label;
						
					}	else
					{
						std::string label = gen_label();
						$1.tipo = $3.tipo;
						$1.traducao = $1.traducao + "\t" + label + " = " + $3.tipo + " " + $1.label + ";\n";
						$1.label = label;
			
					}		
				}
				$$.label = gen_label();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label +" "+ $2.label +" "+ $3.label + ";\n";
				$$.tipo = $1.tipo;
				
			}
			
			| TK_ID '=' E //atribuição
			{
				if(declarationList.str().find($1.label) == std::string::npos)
					yyerror("\n" + $1.label +" não foi declarada");
				if($1.tipo != $3.tipo)
					yyerror("tipos diferentes");
				$$.label = $1.label; // Label da expressão = Label/nome da variavel
				$$.traducao = $3.traducao + "\t" + $1.label + " = " + $3.label + ";\n"; //mantem tradução da expressão + Nome da variavel = Variavel temporaria da expressão 
				$$.tipo = $1.tipo;
				 				
			}
			
			|	 '('TK_TIPO')' TK_NUM
			{
				$$.label =  gen_label();
				$$.traducao = $4.traducao + "\t" + $$.label + " = " + $4.label +";\n";
				$$.tipo = $2.traducao;
				
			}
			
			| TK_NUM
			{
				std::string label = gen_label();
				$$.label = label; //temp n
				$$.traducao = "\t" + label + " = " + $1.traducao + ";\n"; //tem n = valor do numero
				$$.tipo = $1.tipo;
			}

			| TK_REAL
			{
				std::string label = gen_label();
				$$.label = label; //temp n
				$$.traducao = "\t" + label + " = " + $1.traducao + ";\n"; //tem n = valor do numero
				$$.tipo = $1.tipo;
			}

			| TK_ID
			{			
				if(declarationList.str().find($1.label) == std::string::npos)
					yyerror("\n" + $1.label +" não foi declarada");
				std::string label = gen_label();
				$$.label = label; //temp n
				$$.traducao = "\t" + label + " = " + $1.label + ";\n"; //temp n = "nome da variavel"
							
			}

			
			
DECLARACAO	: DECLARACAO '=' E
			{
				//std::string label = gen_label();
				if($1.tipo != $3.tipo)
					yyerror("tipos incompativeis");
				$$.label = $1.label;
				//declarationList << "\t" << $1.traducao << " " << $2.label << ";\n";
				$$.traducao = $3.traducao + "\t"+ $1.label + " = " + $3.label +";\n";
				
			}
			
			|	TK_TIPO TK_ID
			{
				
				//std::string label = gen_label();
				$$.label = $2.label;
				declarationList << "\t" << $1.traducao << " " << $2.label << ";\n";
				$$.traducao = ""; 
				$$.tipo = $1.traducao;
				
			}
			 
			
			;

%%

#include "lex.yy.c"

int yyparse();

std::string gen_label()
{
	std::stringstream label;
    label << "temp" << label_i++;
    return label.str();
}

string printDeclaracoes()
{
	stringstream declaracoes; 
	
	for(int i = 0; i < label_i; i++)
	{
		declaracoes << "\tint temp" << i <<";\n";
	}
	declaracoes << declarationList.str() << "\n";
	
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
