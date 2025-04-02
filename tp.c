#include "indice_invertido.h"
#include "lista.h"


int main(void){

	IndiceInvertido *indice = aloca_indice(6);

	insere_documento(indice, (Registro){"prog.doc", {"algoritmo", "selecao"}, 2});
	insere_documento(indice, (Registro){"aeds1.doc", {"algoritmo", "estrutura", "dados"}, 3});
	insere_documento(indice, (Registro){"darwin.doc", {"selecao", "natural"}, 2});

	imprime(indice);
	libera_indice(indice);

}
