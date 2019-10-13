#ifndef _MYMALLOC_H
#define _MYMALLOC_H
        #define malloc(x) mymalloc((x), __LINE__, __FILE__)
	#define free(x) myfree((x), __LINE__, __FILE__)

        typedef struct meta{
                unsigned int size : 14;
                struct meta* next;
        }meta;

        char mem[4096];

	void* mymalloc(int, int, char*);
	void myfree(void*, int, char*);

#endif
