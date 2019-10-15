#include "mymalloc.h"

void* mymalloc(int requested, int line, char* file){
	if(requested == 0){	
		printf("Error: Attempt to malloc 0 bytes in line %d of file %s\n", line, file);	
		return NULL;
	}

	if (mem[0] == '\0'){ //if no meta struct exists yet in mem, create the first one.
		meta* ptr = (void*) mem;
		(ptr -> size) = 4096 - sizeof(meta); //set 13 bits to size of available space
		(ptr -> isfree) = 1; //set 14th bit to true (aka to 1)
	}

	char* ptr = (void*) mem;
	while (ptr <= mem + 4093){
		meta* block = (meta*) ptr;
		if ((block -> isfree == 1) && (block -> size >= requested)){ //if the block is free AND the size of the available space is >= size of requested data
			void* usrptr = (void*) (block+1);
			int leftover_space = (block -> size) - requested;
			if (leftover_space > sizeof(meta)){
				//create split off free block with unused leftover space
				meta* newblock = (meta*)(ptr + sizeof(meta) + requested);
				(newblock -> size) = leftover_space - sizeof(meta);
				(newblock -> isfree) = 1; 
			}
			(block -> size) = requested;
			(block -> isfree) = 0; //set our isfree bit to 0 since the block is now not free
			return usrptr; //return void pointer which points to memory space that user requested	
		}
		ptr += sizeof(meta) + (block -> size);
	}	
	printf("Error: Saturation of dynamic memory in line %d of file %s\n", line, file);	
	return NULL;
}


void myfree(void* usrptr, int line, char* file){
	if (mem[0] == '\0'){ 		
		printf("Error in attempting to free user ptr %p: in file %s, in line %d\n", usrptr, file, line);
		return;
	}
	char* ptr = (void*) mem;
	char* next = (void*)(ptr + sizeof(meta) + (((meta*)ptr) -> size));

	if (((void*)(ptr + sizeof(meta)) == usrptr) && (((meta*)ptr) -> isfree == 0)){
		if(next <= mem + 4093){
			if(((meta*)next) -> isfree == 1){
					(((meta*)ptr) -> size) += sizeof(meta) + (((meta*)next) -> size);
			}
		}
		((meta*)ptr) -> isfree = 1;	
		return; 
	}

	while(next <= mem + 4093){		
		if (((void*)(next + sizeof(meta)) == usrptr) && (((meta*)next) -> isfree == 0)){
			char* nextnext = (next + sizeof(meta) + (((meta*)next) -> size));
			if(nextnext <= mem + 4093){
				if(((meta*)nextnext) -> isfree == 1){
					(((meta*)next) -> size) += sizeof(meta) + (((meta*)nextnext) -> size);
				}
			}
			((meta*)next) -> isfree = 1;
			if(((meta*)ptr) -> isfree == 1){
				(((meta*)ptr) -> size) += sizeof(meta) + (((meta*)next) -> size);	
			}
			return;
		}
		ptr = next;
		next += sizeof(meta) + (((meta*)next) -> size);
	}
	printf("Error in attempting to free user ptr %p: in file %s, in line %d\n", usrptr, file, line);
	return;

}




