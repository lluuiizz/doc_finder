#include "indice_invertido.h"
#include "hash.h"
#include <stdlib.h>
#include <stdio.h>


IndiceInvertido* aloca_indice(int capacidade){
	IndiceInvertido* novo = (IndiceInvertido*) malloc(sizeof(IndiceInvertido));
	novo->capacidade = capacidade;
	novo->listas = (Lista**) malloc(sizeof(Lista*) * capacidade);

	for (int i = 0; i < capacidade;i++)
		novo->listas[i] = inicia_lista();

	novo->qnt_chaves_diferentes = 0;
	return novo;
}
void libera_indice(IndiceInvertido *indice){
	for (int i = 0; i < indice->capacidade;i++)
		liberar_lista(indice->listas[i]);

	free(indice->listas);
	free(indice);

}


void insere_documento(IndiceInvertido *indice, Registro reg){
	int nao_correspondencias = 0;
	for (int i = 0; i < reg.qnt_chaves; i++){
		int indice_para_chave = busca(indice, reg.chaves[i]);
		strncpy(indice->chaves_ja_inseridas[indice_para_chave], reg.chaves[i], strlen(reg.chaves[i]));


		inserir_na_lista(indice->listas[indice_para_chave], reg);

	}
}
int busca (IndiceInvertido *indice, Chave chave){

	int indice_da_lista = h(chave, indice->capacidade);

	if (strcmp(indice->chaves_ja_inseridas[h(chave, indice->capacidade)], chave) != 0){
		bool encontrou = false;
		do {
			indice_da_lista = (indice_da_lista+1) % indice->capacidade;
			encontrou = strcmp(indice->chaves_ja_inseridas[indice_da_lista], chave) != 0 ? false : true;


		} while (!encontrou  && indice->listas[indice_da_lista]->tamanho != 0);

		if (!encontrou)
			indice->qnt_chaves_diferentes++;

	}
	return indice_da_lista;

}
void consulta (IndiceInvertido* indice, Registro chaves){

	int indice_lista = busca(indice, chaves.chaves[0]);

	busca_lista(indice->listas[indice_lista], chaves);

}
void imprime(IndiceInvertido* indice){

	No *aux;	
	for (int i = 0;  i < indice->capacidade; i++){
		if (strlen(indice->chaves_ja_inseridas[i]) != 0){
			int indice_da_lista = busca(indice, indice->chaves_ja_inseridas[i]);
			printf("%s - ", indice->chaves_ja_inseridas[i]);
			aux = indice->listas[indice_da_lista]->cabeca;

			for (int j = 0; j < indice->listas[indice_da_lista]->tamanho; j++){
				printf("%s ", aux->item.arquivo);
				aux = aux->proximo;
			}
			printf("\n");

		}
	}
	aux = NULL;
}



