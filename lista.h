#ifndef _LISTA_H
#define _LISTA_H

#include <stdbool.h>

typedef int Item;

typedef struct no {
	Item item;
	struct no *proximo;
} No;

typedef struct {
	No *cabeca;
	int tamanho;
} Lista;


Lista* inicia_lista();
void inserir_na_lista(Lista *lista, Item x);
bool buscar_valor (Lista *lista, Item x);





#endif // _LISTA_H
