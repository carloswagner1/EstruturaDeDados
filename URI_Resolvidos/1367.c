/*Ajude!*/
/*Carlos Wagner Rodrigues da Silva*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

#define QTDE_SUB 300


typedef struct{
	char id[2];
	int tempo;
	char resposta[11];
} regLista;

typedef struct{
	int final;
	regLista lista[QTDE_SUB];
}TDescr;

void inicializalizaLista(TDescr *);
void IncluiLista(TDescr *, int);
int procuraQuestao(char*, char *);
int procuraQuestaoPosi(char*, char *);

/*void ImprimeLista(TDescr *, char *);
int ExcluiFuncionario(TDescr *, int);*/


int main(){
	int n; /*, i, tempoTotal, acertos;*/
	TDescr lista;
	/*char idQuestoes[26];
	int erros[n];

	i = 0;
	tempoTotal = 0;
	acertos = 0;
	memset(erros, 0, sizeof(erros));*/


	scanf("%d", &n);

	while(n != 0){
		inicializalizaLista(&lista);

		IncluiLista(&lista, n);

		/*if (procuraQuestao(idQuestoes, lista.lista[i].id)){
			if (strcmp(lista.lista[i].resposta, "correct") == 0){
				acertos++;
				tempoTotal += lista.lista[i].tempo + erros[procuraQuestaoPosi(idQuestoes, lista.lista[i].id)];
				// Se a questão existe e está correta, apenas soma o tempo total da questão
				// Mais o tempo das eventuais penalidades que essa questão já teve ao tempo total;
			}else{
				erros[procuraQuestaoPosi(idQuestoes, lista.lista[i].id)] += 20;
				// Se a questão já existe, mas está incorreta, apenas some 20
				// Segundos no vetor de penalidades na posição dessa questão;

			}
		}else if (strcmp(lista.lista[i].resposta, "correct") == 0){
			acertos++;
			idQuestoes[i] = lista.lista[i].id;
			tempoTotal += lista.lista[i].tempo;
			// Se a questão não existe e está correta, adiciona essa questão
			// No banco, incrementa a quantidade de questões corretas e
			// Soma ao tempo total o tempo da questão;

			i++;

		}else{
			idQuestoes[i] = lista.lista[i].id;
			erros[i] += 20;
			// Se a questão não existe e está incorreta, adiciona a questão
			// No banco e soma 20 segundos no vetor de penalidades na posição da questão;
			i++;

		}*/

		scanf("%d", &n);
	}
/*	if (acertos == 0)
		printf("0 0\n");
	else
		printf("%d %d\n", acertos, tempoTotal);*/


	return 0;
}

void inicializalizaLista(TDescr *lst){
	lst->final = -1;
}


void IncluiLista (TDescr *lst, int num){
	int i;

	for(i=0; i < num; i++){
		scanf("%c %d %10[^\n]", lst->lista[i].id, &lst->lista[i].tempo, lst->lista[i].resposta);
	}
	
}
/*
// Função verifica se uma questão existe no banco de questões;
int procuraQuestao( char *idQuestoes, char *id)
{

	while (*idQuestoes)
		if (*(idQuestoes++) == id)
			return TRUE;

	return FALSE;
}

// Função procura a posição de uma questão existente no banco de questões;
int procuraQuestaoPosi(char *idQuestoes, char *id)
{

	int i = 0;

	while (idQuestoes[i])
	{
		if (idQuestoes[i] == id)
			return i;

		i++;
	}

}
*/