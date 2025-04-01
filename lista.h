#ifndef _LISTA_H
#define _LISTA_H

#include <stdbool.h>

typedef char Documento[50];
typedef char Chave[20];

typedef struct {
	Documento arquivo;
	Chave chaves[1000];
	int qnt_chaves;
} Registro;


typedef struct no {
	Registro item;
	struct no *proximo;
} No;

typedef struct {
	No *cabeca;
	int tamanho;
} Lista;


Lista* inicia_lista();
void inserir_na_lista(Lista *lista, Registro x);
bool busca_lista (Lista *lista, Registro x);
void liberar_lista (Lista *lista);
void imprime_lista (Lista *lista);





#endif // _LISTA_H
