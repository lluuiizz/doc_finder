all: tp.o hash.o indice_invertido.o merge_sort.o lista.o
	@gcc tp.o hash.o indice_invertido.o merge_sort.o lista.o -o exe
	@rm -r merge_sort.o lista.o hash.o indice_invertido.o tp.o
tp.o: tp.c
	@gcc tp.c -c -Wall
indice_invertido.o: indice_invertido.c
	@gcc indice_invertido.c -c -Wall
hash.o: hash.c
	@gcc hash.c -c -Wall
merge_sort.o: merge_sort.c
	@gcc merge_sort.c -c -Wall
lista.o: lista.c
	@gcc lista.c -c -Wall
 
run:
	@./exe
val:
	@gcc -g -o exeval merge_sort.c lista.c hash.c indice_invertido.c tp.c -Wall
valrun: val
	@valgrind --leak-check=full --track-origins=yes -s ./exeval
