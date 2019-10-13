#include "mymalloc.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct meta{
	unsigned int size : 14;
	struct* next;
} meta;

char mem[4096];


void* mymalloc(int requested, int __LINE__, char* __FILE__){

}


void myfree(void* usrptr, int __LINE__, char* __FILE__){


}



//int main(int argc, char** argv){
//
//        int n = 0;
//        if (n < 10){
//	        printf("working!!");
//                n++;
//
//                int j = 0;
//                if (j < 10){
//                        printf("Working2!");
//                        j++;
//                }
//        }
//
//	return 0;
//}

