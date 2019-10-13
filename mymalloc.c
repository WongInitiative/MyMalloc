#include "mymalloc.h"

//typedef struct meta{
//	unsigned int size : 14;
//	struct meta* next;
//}meta;
//
//char mem[4096];

void* mymalloc(int requested, int __LINE__, char* __FILE__){

	printf("Working myMalloc");

	return NULL;
}


void myfree(void* usrptr, int __LINE__, char* __FILE__){

	printf("Working myFree");	

	return NULL;
}




