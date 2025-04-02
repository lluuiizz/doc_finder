#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Lista* inicia_lista() {

	Lista *nova_lista = (Lista*) malloc(sizeof(Lista));
	nova_lista->cabeca  = NULL;
	nova_lista->tamanho = 0;

	return nova_lista;
}
void inserir_na_lista(Lista *lista, Registro x){

	No *novo_no = (No*) malloc(sizeof(No));
	novo_no->item = x;
	novo_no->proximo = NULL;

	if (lista->cabeca == NULL){
		lista->cabeca = novo_no;
		lista->tamanho++;
		return;
	}

	No *aux = lista->cabeca;

	while (aux->proximo != NULL)
		aux = aux->proximo;

	aux->proximo = novo_no;

	lista->tamanho++;

}
bool busca_lista (Lista *lista, Registro x){

	No *aux = lista->cabeca;
	int correspondencias = 0;
	bool achou_algum = false;

	for (int i = 0; i < lista->tamanho; i++){
		for (int j = 0; j < aux->item.qnt_chaves; j++){
			for (int k = 0; k < x.qnt_chaves; k++){
				if(strcmp(x.chaves[k], aux->item.chaves[j]) == 0){
					correspondencias++;

				}
			}

		}
		if (correspondencias == x.qnt_chaves){
			printf("%s\n", aux->item.arquivo);
		}
		aux = aux->proximo;
		correspondencias = 0;
	}

	
	return achou_algum;

}

void imprime_lista (Lista *lista){
	No *aux = lista->cabeca;

	for (int i = 0; i < lista->tamanho; i++){
		printf("%s ", aux->item.arquivo);
		aux = aux->proximo;
	}
	printf("\n");


}

void liberar_lista (Lista *lista){
	No *aux = lista->cabeca;

	while (aux != NULL){
		No *temp = aux;
		aux = aux->proximo;
		free(temp);

	}
	free(lista);
}



