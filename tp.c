#include "indice_invertido.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){

	int n_documentos;

	scanf("%d ",&n_documentos );

	Registro *arquivos = (Registro*) malloc(sizeof(Registro) * n_documentos);
	arquivos->qnt_chaves = 0;

	char buffer[500];

	for (int i = 0; i < n_documentos; i++){
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strcspn(buffer, "\n")] = '\0';

		char *token = strtok(buffer, " ");

		if (token != NULL){
			strcpy(arquivos[i].arquivo, token);
			token = strtok(NULL, " ");
		}

		while (token != NULL ){
			strcpy(arquivos[i].chaves[arquivos[i].qnt_chaves], token);
			arquivos[i].qnt_chaves++; 
			token = strtok(NULL, " ");
		}
	}


	IndiceInvertido *indice = aloca_indice(10);
	for (int i = 0; i < n_documentos; i++)
		insere_documento(indice, arquivos[i]);


	char opcao;

	fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = '\0';

	char *token = strtok(buffer, " ");
	if (token != NULL){
		opcao = token[0];
		token = strtok(NULL, " ");
	}

	switch (opcao){
			Registro pesquisa;
			int i;
		case 'B':
			i = 0;
			while (token != NULL){
				strcpy(pesquisa.chaves[i++], token);
				token = strtok(NULL, " ");
			}
			pesquisa.qnt_chaves = i;
			consulta(indice, pesquisa);
			break;
		case 'I':
			imprime(indice);
			break;
		default:
			break;

	}


}
