#include "mymalloc.h"

void* mymalloc(int requested, int line, char* file){
	if (mem[0] = '0')
		printf("initizlized");
	meta* ptr1 = (void*) mem;
	ptr1 -> isfreeNsize = 4096 - sizeof(meta); //set 13 bits to size of free space
	(ptr1 -> isfreeNsize) |= (1 << 13); //set 14th bit to true
	ptr1 -> next = NULL; //set next pointer equal to null
	if (mem[0] != '0')
		printf("FUCK COCK DICK");


	meta* ptr = (void*) mem;
	int isfree = (((ptr -> isfreeNsize) >> 13) & 1);
	int size = (ptr -> isfreeNsize) &= ~(1 << 13);
	printf("is free is %d, size is %d, size is also%d\n", isfree, mem[0], 4096 - sizeof(*ptr));
	printf("Working myMalloc");

	return NULL;
}


void myfree(void* usrptr, int line, char* file){
//
//        ///Initialize a ptr
//	printf("Working myFree");
//	meta * ptr = (void *) mem;
//
//
//        ///Ptr Traversal
//        while ((void *)(ptr->next + 1) != usrptr && ptr->next == NULL){
//                ptr = ptr->next;
//        }
//
//	if ((ptr-> next + 1) != usrptr){
//		printf("Error in ptr to free  %p: in file %s, in line %d");
//		return; 	
//	}
//
//        ///Bit arithmetic
//        ptr->isfreeNsize &= ~(1<<13);
//
//        meta * head = ptr;
//        ptr = ptr-> next;
//        while (((ptr->isfreeNsize) >> 13) & 1 == 0 || ptr != NULL){
//                head->isfreeNsize += ptr->isfreeNsize;
//                ptr = ptr->next;
//        }
//
//        head->next = ptr;
//
//
//
	return;
}




