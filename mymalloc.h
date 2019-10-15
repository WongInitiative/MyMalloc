#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#ifndef _MYMALLOC_H
#define _MYMALLOC_H
	#define malloc(x) mymalloc((x), __LINE__, __FILE__)
	#define free(x) myfree((x), __LINE__, __FILE__)

        typedef struct meta{ //took a decent BIT of effort figuring out how to make this smaller (can I have more points for the pun please I'm desperate)
                unsigned int size : 14; //creates bitfield of exactly 14 bits. 13 bits for the size of the usable space(which must be less than 4096), 1 bit leftover to represent if block is free or not
                unsigned int isfree : 1; //pointer to next block (aka next metadata struct)
        }__attribute__((packed, aligned(1))) meta; //get rid of byte padding to save space :^)

	char mem[4096];
	
	void* mymalloc(int, int, char*);
	void myfree(void*, int, char*);

#endif
