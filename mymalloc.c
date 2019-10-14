#include "mymalloc.h"

void* mymalloc(int requested, int line, char* file){
	meta* ptr = (void*) mem;
	int isfree = (((ptr -> isfreeNsize) >> 13) & 1);
	int size = (ptr -> isfreeNsize) &= ~(1 << 13);
	printf("%d\n", mem[0]);
	printf("Working myMalloc");

	return NULL;
}


void myfree(void* usrptr, int line, char* file){

	printf("Working myFree");

	meta * ptr = (void *) mem;
	meta* temp = (void *) mem;

        ///Ptr Traversal
        while ((void *)(ptr + 1) != usrptr){
                temp = temp->next;
        }

        while ((void*) ptr->next != (void*) temp){
		ptr = ptr->next;	
	}

	
	


	return;
}




