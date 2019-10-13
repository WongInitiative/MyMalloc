#include "mymalloc.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>


void* mymalloc(int requested, int line, char* file){

	printf("Working myMalloc");

	return NULL;
}


void myfree(void* usrptr, int line, char* file){

	printf("Working myFree");

	return NULL;
}




