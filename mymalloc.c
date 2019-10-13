#include "mymalloc.h"

#include <stdio.h>
#include <stdlib.h>


void* mymalloc(int requested, int __LINE__, char* __FILE__){

	printf("Working myMalloc");

	return NULL;
}


void myfree(void* usrptr, int __LINE__, char* __FILE__){

	printf("Working myFree");

	return NULL;
}




