#include "mymalloc.h"

void* mymalloc(int requested, int line, char* file){
	meta* ptr = (void*) mem;
	if (mem[0] == '\0'){ //if no meta struct exists yet in mem, create the first one.
		(ptr -> isfreeNsize) = 4096 - sizeof(meta); //set 13 bits to size of available space
		(ptr -> isfreeNsize) |= (1 << 13); //set 14th bit to true (aka to 1)
		(ptr -> next) = NULL; //set next pointer equal to null
	}
	if(requested > 4086)
		printf("Error: Saturation of dynamic memory in line %d of file %s\n", line, file);	
	while (ptr != NULL){
		int isfree = (((ptr -> isfreeNsize) >> 13) & 1);//check 14th bit value
		int block_size = (ptr -> isfreeNsize) &= ~(1 << 13);//set 14th bit value to 0 and get size of available space
		if ((isfree == 1) && (block_size >= requested)){ //if the block is free AND the size of the available space is >= size of requested data
			void* usrptr = (void*) (ptr+1);
			int leftover_space = block_size - requested;
			if (leftover_space > sizeof(meta)){
				//create split off free block with unused leftover space
				(ptr -> isfreeNsize) = requested;
				meta* newblock = ptr + sizeof(meta) + requested;
				(newblock -> isfreeNsize) = leftover_space - sizeof(meta);
				(newblock -> isfreeNsize) |= (1 << 13); 
				(newblock -> next) = NULL; 
				(ptr -> next) = newblock;
			}
			(ptr -> isfreeNsize) &= ~(1 << 13); //set our isfree bit to 0 since the block is now not free
			return usrptr; //return void pointer which points to memory space that user requested	
		}
		ptr = ptr -> next;
	}	
	printf("Error: Saturation of dynamic memory in line %d of file %s\n", line, file);	
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




