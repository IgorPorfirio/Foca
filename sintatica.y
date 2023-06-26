 %{
#include <iostream>
#include <string>
#include <sstream>
#include <map>
int label_i = 0;



#define YYSTYPE atributos


std::map<std::string, std::pair<std::string, std::string>> variableTable; //Nome da variavel, nome temporario e tipo da variavel.
std::map<std::string, std::pair<std::string, std::string>> reverseTable;  //nome temporario, nome da variavel e tipo da variavel

void addVariable(const std::string& nomeVar, const std::string& nomeTemp, const std::string& type) {
    variableTable[nomeVar] = std::make_pair(nomeTemp, type);
	reverseTable[nomeTemp] = std::make_pair(nomeVar, type);
}

std::pair<std::string, std::string> getVariableInfo(const std::string& codeName) {
    return variableTable[codeName];
}

using namespace std;

struct atributos
{
	string label;
	string traducao;
	string tipo;
};

std::string getDominantType(const std::string& tipo1, const std::string& tipo2);
string printDeclaracoes();
int yylex(void);
void yyerror(string);

std::string gen_label();

atributos implicitTypeCast(const atributos& original, const atributos& destino); 

%}

%token TK_NUM TK_REAL TK_BOOL TK_CHAR
%token TK_TIPO
%token TK_MAIN
%token TK_ID 
%token TK_FIM TK_ERROR
%token TK_OP TK_OP2
%token TK_RELACIONAL
%token TK_LOGICO
%token TK_UNARIO
%token TK_IF
%token TK_ELSE
%start S






%left TK_OP 
%left TK_OP2

//%left TK_RELACIONAL TK_LOGICO
//%left TK_UNARIO

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

			| TK_IF '(' E ')' BLOCO TK_ELSE BLOCO
			;

COMANDOS	: COMANDO COMANDOS
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			| {
				$$.traducao = "";
			}
			;

COMANDO 	: E ';'
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = $1.tipo;
			}
			; 

E 			: E TK_OP E 
			{	
				if($1.tipo == "bool" || $3.tipo == "bool")
					yyerror("Operação entre não booleanos não é possível");
				std::string label = gen_label();
				addVariable(label, label, $1.tipo);
				$$.label = label;
				$$.tipo = getDominantType($1.tipo, $3.tipo);
				$$.traducao = $1.traducao + $3.traducao;
				if ($1.tipo != $$.tipo) {
					atributos typecast = implicitTypeCast($1, $$);
					$$.traducao += typecast.traducao;
					$1.label = typecast.label;
				}
				if ($3.tipo != $$.tipo) {
					atributos typecast = implicitTypeCast($3, $$);
					$$.traducao += typecast.traducao;
					$3.label = typecast.label;
				}
				$$.traducao += "\t" + $$.label + " = " + $1.label + " " + $2.label + " " + $3.label + ";\n";
			}
			| E TK_OP2 E 
			{	
				if($1.tipo == "bool" || $3.tipo == "bool")
					yyerror("Operação entre não booleanos não é possível");
				std::string label = gen_label();
				addVariable(label, label, $1.tipo);
				$$.label = label;
				$$.tipo = getDominantType($1.tipo, $3.tipo);
				$$.traducao = $1.traducao + $3.traducao;
				if ($1.tipo != $$.tipo) {
					atributos typecast = implicitTypeCast($1, $$);
					$$.traducao += typecast.traducao;
					$1.label = typecast.label;
				}
				if ($3.tipo != $$.tipo) {
					atributos typecast = implicitTypeCast($3, $$);
					$$.traducao += typecast.traducao;
					$3.label = typecast.label;
				}
				$$.traducao += "\t" + $$.label + " = " + $1.label + " " + $2.label + " " + $3.label + ";\n";
			}
			
			| E TK_RELACIONAL E
			{
				if($1.tipo == "bool" || $3.tipo == "bool")
					yyerror("Operação entre não booleanos não é possível");
				std::string label = gen_label();
				addVariable(label, label, $1.tipo);
				$$.label = label;
				$$.tipo = getDominantType($1.tipo, $3.tipo);
				$$.traducao = $1.traducao + $3.traducao;
				if ($1.tipo != $$.tipo) {
					atributos typecast = implicitTypeCast($1, $$);
					$$.traducao += typecast.traducao;
					$1.label = typecast.label;
				}
				if ($3.tipo != $$.tipo) {
					atributos typecast = implicitTypeCast($3, $$);
					$$.traducao += typecast.traducao;
					$3.label = typecast.label;
				}
				$$.tipo = "bool";
				$$.traducao += "\t" + $$.label + " = " + $1.label + " " + $2.label + " " + $3.label + ";\n";
			}
			| E TK_LOGICO E
			{
				if($1.tipo != "bool" || $3.tipo != "bool")
					yyerror("Operação lógica entre não booleanos não é possível");
				std::string label = gen_label();
				addVariable(label, label, $1.tipo);
				$$.label = label;
				$$.tipo = "bool";
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " " + $2.label + " " + $3.label + ";\n";
			}


			|	TK_ID '=' E //atribuição
			{
				if (variableTable.find($1.label) == variableTable.end()) 
   					 yyerror("\n" + $1.label + " não foi declarada");
				
				if($1.tipo == "bool" && $3.tipo != "bool")
					 yyerror("booleano não pode receber não booleano");
				$$.tipo = getDominantType($1.tipo, $3.tipo);
				if($1.tipo != $$.tipo)
				{
					atributos typecast = implicitTypeCast($1, $$);
					$$.traducao += typecast.traducao;
					//
					variableTable[$1.label] = std::make_pair(typecast.label, typecast.tipo);
					//cout << variableTable[$1.label].first;
					$1.label = typecast.label;
					
				}
				if ($3.tipo != $$.tipo) {
					atributos typecast = implicitTypeCast($3, $$);
					$$.traducao += typecast.traducao;
					$3.label = typecast.label;
				}
				$$.label = $1.label; // Label da expressão = Label/nome da variavel

				auto id = variableTable.find($1.label);
				
				$$.traducao = $3.traducao + "\t" + id->second.first + " = " + $3.label + ";\n"; //mantem tradução da expressão + Nome da variavel = Variavel temporaria da expressão 
				$$.tipo = $1.tipo;
				 				
			}
			
			|	'('TK_TIPO')' E //%prec TK_UNARIO
			{
				$$.label =  gen_label();
				addVariable($$.label, $$.label, $2.tipo);
				$$.tipo = $2.traducao;
				$$.traducao = $4.traducao + "\t" + $$.label + " = (" +$2.traducao +")" + $4.label + ";\n";
				
				
			}
			
			| TK_NUM
			{
				$$.label = gen_label();
				addVariable($$.label, $$.label, $1.tipo);
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n"; //tem n = valor do numero
				$$.tipo = $1.tipo;
			}

			| TK_REAL
			{
				$$.label = gen_label();
				addVariable($$.label, $$.label, $1.tipo);
				
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n"; 
				$$.tipo = $1.tipo;
			}

			| TK_BOOL
			{
				$$.label = gen_label();
				addVariable($$.label, $$.label, $1.tipo);
				
				if($$.traducao == "TRUE")
					$$.traducao = "\t" + $$.label + " = " + "1" + ";\t\t\t\t//boolean TRUE\n"; 
				else
					$$.traducao = "\t" + $$.label + " = " + "0" + ";\t\t\t\t//boolean FALSE\n"; 
				$$.tipo = $1.tipo;
			}
			| TK_CHAR
			{
				$$.label = gen_label();
				addVariable($$.label, $$.label, $1.tipo);
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
        		$$.tipo = "char";
			}

			| TK_ID
			{			
				if (variableTable.find($1.label) == variableTable.end()) 
   					yyerror("\n" + $1.label + " não foi declarada");
				std::string label = gen_label();
				$$.label = label; //temp n
				$$.traducao = "\t" + label + " = " + $1.traducao + ";\n"; 
				$$.tipo = variableTable[$1.label].second;
			}
		

			| TK_TIPO TK_ID '=' E
			{
				//std::string label = gen_label();
				if($1.tipo != $4.tipo)
					yyerror("tipos incompativeis");
				
				$$.label = gen_label();
				addVariable($2.label, $$.label, $1.tipo);
				$$.traducao = $4.traducao + "\t" + $2.label + " = " + $4.label + ";\n";
				$$.tipo = $1.tipo;
				
			}
			
			|	TK_TIPO TK_ID
			{
						
				$$.label = gen_label();
				addVariable($2.label, $$.label, $1.tipo);
				$$.traducao = "";
				$$.tipo = $1.tipo;
				
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

std::string getDominantType(const std::string& tipo1, const std::string& tipo2) {
    if (tipo1 == "float" || tipo2 == "float") {
        return "float";
    } else {
        return "int";
    }
}

atributos implicitTypeCast(const atributos& original, const atributos& destino) {
    atributos result;
    result.label = gen_label();
	
    if (original.tipo != destino.tipo) {
        
    	result.traducao = "\t" + result.label + " = " + "(" + destino.tipo + ")" + original.label + ";\n";
        
    } else {
        // No type casting needed, assign the original value
        result.traducao = "\t" + result.label + " = " + original.label + ";\n";
    }
	
    result.tipo = destino.tipo;
	addVariable(result.label, result.label, result.tipo);
    return result;
}

string printDeclaracoes()
{
	stringstream declaracoes; 
	
	for(int i = 0; i < label_i; i++)
	{
		string variable = "temp" + to_string(i);

		if (reverseTable.find(variable) == reverseTable.end())
		{
			declaracoes << "\tint temp" << i <<";\n";
		}else
		{
			const auto& entry = reverseTable.find(variable)->second;
            string variableType = entry.second;
			if(variableType == "bool")
				variableType = "int";
            const string& variableName = entry.first;
            declaracoes << "\t" << variableType << " " << variable << ";\t\t\t\t// variavel " << variableName << "\n";
		}
		
	}
	
	
	
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
