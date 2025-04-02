#ifndef _MERGE_SORT_H
#define _MERGE_SORT_H

#include "lista.h"

void dividir(No *cabeca, No **frente, No **tras);
No* mesclar_listas (No *a, No *b);
void merge_sort(No **cabeca);






#endif // _MERGE_SORT_H
