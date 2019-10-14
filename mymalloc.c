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

        ///Ptr Traversal
        while ((void *)(ptr-> + 1) != usrptr && ptr->next == NULL){
                ptr = ptr->next;
        }

        ///Bit artihmetic
        ptr->isfreeNsize &= ~(1<<13);

        meta * head = ptr;
        ptr = ptr-> next;
        while ((ptr->isfreeNsize) >> 13) & 1 == 0){
                head->isfreeNsize += ptr->isfreeNsize;
                ptr = ptr->next;
        }
        head = ptr;






	return;
}




