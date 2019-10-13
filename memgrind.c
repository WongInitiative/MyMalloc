#include "mymalloc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



int main(int argc, char* argv[]){

	int * ptr = (int*) malloc(1);
	free(ptr);

	return 0;
}




