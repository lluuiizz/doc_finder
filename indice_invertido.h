#ifndef _INDICE_INVERTIDO_H
#define _INDICE_INVERTIDO_H

#include "lista.h"

typedef struct {
	Lista **listas;
	Chave chaves_ja_inseridas[1000];
	int qnt_chaves_diferentes;
	int capacidade;

} IndiceInvertido;


IndiceInvertido* aloca_indice(int capacidade);
void libera_indice(IndiceInvertido *);
void insere_documento(IndiceInvertido *, Registro reg);
int busca (IndiceInvertido *, Chave chave);
void consulta (IndiceInvertido* indice, Registro chaves);
void imprime(IndiceInvertido*);





#endif  // _INDICE_INVERTIDO_H
