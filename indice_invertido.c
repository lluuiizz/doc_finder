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
		inserir_na_lista(indice->listas[busca(indice, reg.chaves[i])], reg);

		if (indice->qnt_chaves_diferentes == 0){
			strncpy(indice->chaves_ja_inseridas[indice->qnt_chaves_diferentes++], reg.chaves[i], strlen(reg.chaves[i]));
		}
		else {
			for (int j = 0; j < indice->qnt_chaves_diferentes; j++){
				printf("%s x %s\n", indice->chaves_ja_inseridas[j], reg.chaves[i]);
				if (strcmp(reg.chaves[i], indice->chaves_ja_inseridas[j]) != 0)
					nao_correspondencias++;

			}
			if (nao_correspondencias == indice->qnt_chaves_diferentes){
				strncpy(indice->chaves_ja_inseridas[indice->qnt_chaves_diferentes++], reg.chaves[i], strlen(reg.chaves[i]));
				nao_correspondencias = 0;
			}

		}
	}
}
int busca (IndiceInvertido *indice, Chave chave){

	int indice_da_lista = h(chave, indice->capacidade);
	return indice_da_lista;

}
void consulta (IndiceInvertido* indice, Registro chaves){

	int indice_lista = busca(indice, chaves.chaves[0]);

	busca_lista(indice->listas[indice_lista], chaves);

}
void imprime(IndiceInvertido* indice){

	for (int i = 0;  i < indice->qnt_chaves_diferentes; i++){
		int indice_da_lista = busca(indice, indice->chaves_ja_inseridas[i]);
		printf("%s - ", indice->chaves_ja_inseridas[i]);
		imprime_lista(indice->listas[indice_da_lista]);

	}
}



