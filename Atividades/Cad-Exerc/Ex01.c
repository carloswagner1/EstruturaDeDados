#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef union{
	int unidade;
	float kg;
	float lt;
	float mt;
}Unid_Med;

typedef union{
	int unidade;
	float kg;
	float lt;
	float mt;
}Qtde_Estoque;

typedef struct{
	int codigo;
	char descricao[21];
	Unid_Med unidade;
	Qtde_Estoque qtde;
	float preco_unit;
}TProduto;

int main(){
	TProduto produtos[26];

	
}