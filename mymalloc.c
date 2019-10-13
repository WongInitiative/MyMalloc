#include "mymalloc.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct meta{
	unsigned int size : 14;
	struct* next;
} meta;

char mem[4096];


void* mymalloc(int requested, int __LINE__, char* __FILE__){

	printf("Working myMalloc");

}


void myfree(void* usrptr, int __LINE__, char* __FILE__){

	printf("Working myFree");	
}




