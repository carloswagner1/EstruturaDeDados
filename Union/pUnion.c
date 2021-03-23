#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct { int dia, mes, ano; } TData;

typedef struct { char lograd[51];
				 char complem[25];
				 char bairro[25];
				 char cidade[35];
				 int cep;
				 char uf[3];
				} TEnder;

typedef struct { char nome[41];
				 char cpf[15];
				 char rg[15];
				 char sexo;
				 TData dataNasc; 
				} TPessoa;

typedef struct { char razao[51];
				 char cnpj[19];
				 char inscrEst[14];
				} TEmpresa;

typedef union { TPessoa detCliFis;
				TEmpresa detCliJur;
			  } TDetalhe;

typedef struct { TEnder endereco;
				 TData dataCad;
				 float limiteCred;
				 char tipo;
				 TDetalhe detalhe;
				} TCliente;


int main()
{	TCliente vCliente;

	printf("Informe o tipo do cliente (E = Empresa, P = Pessoa):\n");
	scanf("%c", &vCliente.tipo);
	
	if (vCliente.tipo == 'E' || vCliente.tipo == 'e'){

		printf("Razao social:\n");
		scanf("%s", vCliente.detalhe.detCliJur.razao);
		
		printf("CNPJ:\n");
		scanf("%s", vCliente.detalhe.detCliJur.cnpj);
		
		printf("Inscricao estadual:\n");
		scanf("%s", vCliente.detalhe.detCliJur.inscrEst);
	}
	else if(vCliente.tipo == 'P' || vCliente.tipo == 'p'){
		printf("Nome:\n");
		scanf("%s", vCliente.detalhe.detCliFis.nome);

		printf("CPF:\n");
		scanf("%s", vCliente.detalhe.detCliFis.cpf);

		printf("RG:\n");
		scanf("%s", vCliente.detalhe.detCliFis.rg);

		printf("Sexo:\n");
		scanf(" %c", &vCliente.detalhe.detCliFis.sexo);

		printf("Data de nascimento:\n");
		scanf("%d/%d/%d", &vCliente.detalhe.detCliFis.dataNasc.dia,
						  &vCliente.detalhe.detCliFis.dataNasc.mes,
						  &vCliente.detalhe.detCliFis.dataNasc.ano);
	}else{
		printf("Tipo de cliente inválido.\n");
		exit(0);
	}
	printf("Logradouro:\n");
	scanf("%s", vCliente.endereco.lograd);

	printf("Complemento:\n");
	scanf("%s", vCliente.endereco.complem);

	printf("Bairro:\n");
	scanf("%s", vCliente.endereco.bairro);

	printf("Cidade:\n");
	scanf("%s", vCliente.endereco.cidade);

	printf("UF:\n");
	scanf("%s", vCliente.endereco.uf);

	printf("CEP:\n");
	scanf("%d", &vCliente.endereco.cep);

	printf("Data de Cadastro:\n");
	scanf("%d/%d/%d", &vCliente.dataCad.dia,
						&vCliente.dataCad.mes,
						&vCliente.dataCad.ano);
	printf("Limite de Crédito:\n");
	scanf("%f", &vCliente.limiteCred);

	if(vCliente.tipo == 'E' || vCliente.tipo == 'e'){
		printf("----- Dados do cliente ------\n\n");
		printf("Razão social\n%s\n", vCliente.detalhe.detCliJur.razao);
		printf("CNPJ\n%s\n", vCliente.detalhe.detCliJur.cnpj);
		printf("I.E\n%s\n", vCliente.detalhe.detCliJur.inscrEst);
	}else{
		printf("----- Dados do cliente ------\n\n");
		printf("Nome\n%s\n", vCliente.detalhe.detCliFis.nome);
		printf("RG\n%s\n", vCliente.detalhe.detCliFis.rg);
		printf("CPF\n%s\n", vCliente.detalhe.detCliFis.cpf);
		printf("Data de Nascimento\n%d/%d/%d\n", vCliente.detalhe.detCliFis.dataNasc.dia,
								   vCliente.detalhe.detCliFis.dataNasc.mes,
								   vCliente.detalhe.detCliFis.dataNasc.ano);
		printf("Sexo\n%c\n", vCliente.detalhe.detCliFis.sexo);
	}

	printf("Endereço\n%s - %s\n", vCliente.endereco.lograd,	
								   vCliente.endereco.complem);
	printf("%s\n%s - %s CEP: %d\n", vCliente.endereco.bairro,
								    vCliente.endereco.cidade,
								    vCliente.endereco.uf,
								    vCliente.endereco.cep);
	printf("Data do Cadastro\n%d/%d/%d\n", vCliente.dataCad.dia,
											 vCliente.dataCad.mes,
											 vCliente.dataCad.ano);
	printf("Limite de Crédito\n%.2f\n", vCliente.limiteCred);

	return 0;
}
