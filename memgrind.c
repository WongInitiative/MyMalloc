#include "mymalloc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

//#define malloc(x) mymalloc(requested, __LINE__, __FILE__)
//#define free(x) myfree(usrptr, __LINE__, __FILE__)

void workLoad1();
void workLoad2();
void workLoad3();
void workLoad4();
void workLoadUnique1();
void workLoadUnique2();



int main(int argc, char* argv[]){


	///General Testing:

	//char* ptr = (char *) malloc(1);
	//printf("%x", ptr);

		
	//char* fuck3 = (char*)malloc(4087);

	int* ptrInt = (int *) malloc (4*sizeof(int));
	ptrInt[0] = 1;
	ptrInt[1] = 2;
	ptrInt[2] = 3;
	ptrInt[3] = 4;

	printf("%p", ptrInt);	
	free(ptrInt); 
	printf("%p", ptrInt);	

	meta* ballsack = (void*) mem;
	int is_free = (((ballsack->isfreeNsize) >> 13) & 1);
	(ballsack->isfreeNsize) &= ~(1<<13);
	int block_size = (ballsack->isfreeNsize);

	printf("free%d\n block%d\n", is_free, block_size);	


//	printf("%p\n", (void*) &ptrInt[3]);

	double* ptrDouble = (double *) malloc(5*sizeof(double));	
	ptrDouble[0] = 5.0;
	ptrDouble[1] = 6.0;
	ptrDouble[2] = 7.0;
	ptrDouble[3] = 8.0;
	
	printf("%f %f %f\n", ptrDouble[1], ptrDouble[2], ptrDouble [3]);


	//char* fuck = (char*) malloc(4005);
	
	//char* fuck2 = (char*) malloc(4);


	
//	char* fuck = (char*)malloc(4010);
//	int i;
//	for(i = 0; i < 4010; i++){
//		fuck[i] = 'b';	
//	}
//	
//		
//	for(i = 0; i < 4010; i++){
//		char test = fuck[i];	
//		printf("fuckk[%d] is %c\n", i, test);
//	}





//	void* fuck2 = malloc(1);

//	printf("%p\n", (void*) &ptrDouble[0]);
//	//printf("%d, %d\n", ptrDouble[0], mem[200]);
//	
//	meta* ptr = (void*) mem;
//	printf("%d\n", ((ptr->next)->isfreeNsize));
//	printf("%d\n", *((int*)(ptr + 1)));
//	printf("%d\n", *(((int*)(ptr + 1))+1));
//	printf("%d\n", *(((int*)(ptr + 1))+2));
//	printf("%d\n", *(((int*)(ptr + 1))+3));
//	printf("%f\n", *((double*)((ptr->next) + 1)));
//	printf("%f\n", *(((double*)(ptr->next + 1))+1));
//	printf("%f\n", *(((double*)(ptr->next + 1))+2));
//	printf("%f\n", *(((double*)(ptr->next + 1))+3));
//
//	int* ptr2 = (int*) ptr;
//	int i;
//	for (i = 0; i < 4095; i++)
//		printf("value of %d index is %d\n", i, ptr2[i]);
//	//printf("%d", *();
//	double* temp = (double*)mem;
//	printf("%f\n", *((double*)(((char*)ptr)+10+16+9)));
//	printf("%f\n", *((double*)(((char*)ptr)+10+16+10)));
//	printf("%f\n", *((double*)(((char*)ptr)+10+16+11)));
//	printf("%f\n", *((double*)(((char*)ptr)+10+16+12)));
//	printf("%f\n", *((double*)(((char*)ptr)+10+16+13)));
//	//printf("%d", *(((int*)(ptr->next + 1))+2));
//	//printf("%d", *(((int*)(ptr->next + 1))+3));



	///Workloads
	//workLoad1();
	//workLoad2();

	

	return 0;
}


/// malloc 1 byte and free immediately after
void workLoad1(){

	clock_t start, end;

	int a = 0;
	start = clock(); //start clock
	while (a <150){
		char * ptr = (char*) malloc(sizeof(char));
		free (ptr);
		a++;
	}	

	end = clock(); //end clock	
	double total_time = (double) (end - start)/CLOCKS_PER_SEC;  //Total time 
	double avg_time = total_time/150;
	printf("time it takes to malloc then free 1 byte is: %lf", avg_time);
	
	return;
}



///malloc 150 bytes; after 50 bytes free all of them
void workLoad2(){

	clock_t start, end;

	char* ptr[50];
	
	int a, b = 0;
	
	start = clock (); 
	while (a <150) {
		while (b < 50){
			a++;
			ptr[b] = (char*) malloc(1);
		}
		b = 0;
		while (b < 50){
			free(ptr[b]);	
			b++;
		}
	}	


	end = clock();
	double total_time = (double) (end - start) / CLOCKS_PER_SEC;
	double avg_time = total_time / 3; //Time it takes to malloc and free an array of 50
	printf("Time it took to malloc and free an array of 50 ptrs is: %lf", avg_time);

	return;

}

///Randomly choose between 1 byte malloc or freeing 1 byte free
void workLoad3(){

	
}



void workLoad4(){

}

void workLoadUnique1(){


}

void workLoadUnique2(){


}
