#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

Lista* inicia_lista() {

	Lista *nova_lista = (Lista*) malloc(sizeof(Lista));
	nova_lista->cabeca  = NULL;
	nova_lista->tamanho = 0;

	return nova_lista;
}
void inserir_na_lista(Lista *lista, Item x){

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
bool busca_lista (Lista *lista, Item x){

	No *aux = lista->cabeca;

	for (int i = 0; i < lista->tamanho; i++){
		if (aux->item == x)
			return true;
		aux = aux->proximo;
	}

	
	return false;

}

void imprime_lista (Lista *lista){
	No *aux = lista->cabeca;

	for (int i = 0; i < lista->tamanho; i++){
		printf("%d ", aux->item);
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


int main(){
	Lista *lista = inicia_lista();

	inserir_na_lista(lista, 10);
	inserir_na_lista(lista, 5);
	inserir_na_lista(lista, 6);

	imprime_lista(lista);

	liberar_lista(lista);


}
