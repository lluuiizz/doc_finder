#include "include/lista.h"
#include "include/merge_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void dividir(No *cabeca, No **frente, No **tras){
	No *rapido;
	No *lento;

	if (cabeca == NULL || cabeca->proximo == NULL){
		*frente = cabeca;
		*tras = NULL;
	} 
	else {
		lento = cabeca;
		rapido = cabeca->proximo;
		while (rapido != NULL) {
			rapido = rapido->proximo;
			if (rapido != NULL){
				lento = lento->proximo;
				rapido = rapido->proximo;
			}

		}
		*frente = cabeca;
		*tras = lento->proximo;
		lento->proximo = NULL;
	}
}
No* mesclar_listas (No *a, No *b) {
	No *resultado = NULL;

	if (a == NULL) {
		return b;
	}
	else if (b == NULL) {
		return a;	

	}

	if (strcmp(a->item.arquivo, b->item.arquivo) <= 0){
		resultado = a;
		resultado->proximo = mesclar_listas(a->proximo, b);
	}
	else {
		resultado = b;
		resultado->proximo = mesclar_listas(a, b->proximo);

	}

	return resultado;
}
void merge_sort(No **cabeca){
	No *a_cabeca = *cabeca;

	No *a;
	No *b;

	if (a_cabeca == NULL || a_cabeca->proximo == NULL)
		return;

	dividir(a_cabeca, &a, &b);
	merge_sort(&a);
	merge_sort(&b);

	*cabeca = mesclar_listas(a, b);
}


