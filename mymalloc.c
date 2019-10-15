#include "mymalloc.h"

void* mymalloc(int requested, int line, char* file){
	meta* ptr = (void*) mem;
	if (mem[0] == '\0'){ //if no meta struct exists yet in mem, create the first one.
		(ptr -> isfreeNsize) = 4096 - sizeof(meta); //set 13 bits to size of available space
		(ptr -> isfreeNsize) |= (1 << 13); //set 14th bit to true (aka to 1)
		(ptr -> next) = NULL; //set next pointer equal to null
	}
	//if(requested > 4086)
		//printf("Error: Saturation of dynamic memory in line %d of file %s\n", line, file);	
		//return NULL;
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
        ///Initialize a ptr
	meta * ptr = (void *) mem;
	
	///if initial ptr is our usr data
	printf("Stage 1\n");
	
	if (((void*)(ptr + 1)) == usrptr) {
		ptr->isfreeNsize |= (1<<13); //cast leftmost bit to 1
		meta * head = ptr; //points to meta of usrptr
		
	  	while (ptr != NULL){
			if ((ptr ->isfreeNsize) >> 13 & 1 == 0) break;
			//(ptr->isfreeNsize) &= ~(1<<13);
                	head->isfreeNsize += (sizeof(meta) + (ptr->isfreeNsize & ~(1<<13)));
			ptr = ptr->next; 
      		}

 		head->next = ptr;

		return;
	  
	}

        ///if initial ptr is NOT our user data
	printf("Stage 2\n");

        while ((void *)(ptr->next + 1) != usrptr && ptr->next != NULL){
		ptr = ptr->next;
        }

	///Can't find usrptr
	if (ptr->next == NULL){
		printf("Error in attempting to free user ptr %p: in file %s, in line %d\n", usrptr, file, line);
		return; 	
	}

	printf("stage 4\n");
	
        ///Found usrptr; now check if ptr before we're on is used or free;
	if ((ptr->isfreeNsize >> 13) == 0){ //if used
		printf("got into used\n");
		ptr = ptr->next; //have ptr go to the usrptr meta
		ptr->isfreeNsize |= (1<<13); ///Convert to free 
		meta * head = ptr; 
		ptr = ptr-> next;

		while (ptr != NULL){
			ptr = ptr->next; 
			if ((ptr ->isfreeNsize) >> 13 & 1 == 0) break;
                	head->isfreeNsize += (sizeof(meta) + ptr->isfreeNsize);
      		}

	
		head->next = ptr;

	}
 
	else if ((ptr->isfreeNsize >> 13) == 1){ //if free
		meta * head = ptr; ///No conversion necessary 
		ptr = ptr-> next;
		
		while (ptr != NULL){
			ptr = ptr->next; 
			if ((ptr ->isfreeNsize) >> 13 & 1 == 0) break;
                	head->isfreeNsize += (sizeof(meta) + ptr->isfreeNsize);
      		}


		head->next = ptr;

	}


        
	return;
}




