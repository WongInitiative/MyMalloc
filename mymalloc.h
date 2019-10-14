#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#ifndef _MYMALLOC_H
#define _MYMALLOC_H
	#define malloc(x) mymalloc((x), __LINE__, __FILE__)
	#define free(x) myfree((x), __LINE__, __FILE__)

        typedef struct meta{
                unsigned int isfreeNsize : 14;
                struct meta* next;
        }__attribute__((packed, aligned(1))) meta;

        char mem[4096];
	meta* ptr = (void*) mem;
	ptr -> isfreeNsize = 4096 - sizeof(meta); //set 13 bits to size of free space
	(ptr -> isfreeNsize) |= (1 << 13); //set 14th bit to true
	ptr -> next = NULL; //set next pointer equal to null

	void* mymalloc(int, int, char*);
	void myfree(void*, int, char*);

#endif
