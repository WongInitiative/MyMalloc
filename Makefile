all: memgrind.c mymalloc.o
	gcc memgrind.c mymalloc.o -o memgrind -g
mymalloc.o: mymalloc.c
	gcc -c mymalloc.c -g
clean:
	rm memgrind; rm mymalloc.o 
test0:
	./memgrind
