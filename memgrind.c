#include "mymalloc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void workLoad1();
void workLoad2();
void workLoad3();
void workLoad4();
void workLoadUnique1();
void workLoadUnique2();



int main(int argc, char* argv[]){
	
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
}

void testfunc(){
///General Testing:

//	char* smolchungus = (char*) malloc(4091);
//	char* medchung = (char*) malloc(1);
//	char* bigchungus = (char*) malloc(1);

	int* ptrInt = (int *) malloc (4*sizeof(int));
	ptrInt[0] = 1;
	ptrInt[1] = 2;
	ptrInt[2] = 3;
	ptrInt[3] = 4;

	printf("%d\n", *((int*)(mem+1)));

	printf("%d\n", *((int*)(mem+2)));

	printf("%d\n", *((int*)(mem+6)));

	printf("%d\n", *((int*)(mem+10)));
	
	printf("%d\n", *((int*)(mem+2)+3));

	//meta* test = (void*)mem;
	printf("size is %d\n free is %d\n", ((meta*)(mem+18)) -> size, ((meta*)(mem+18)) -> isfree);

	
	
	double* ptrDouble = (double *) malloc (4*sizeof(double));
	ptrDouble[0] = 5;
	ptrDouble[1] = 6;
	ptrDouble[2] = 7;
	ptrDouble[3] = 8;
/*
	printf("%f\n", *((double*)(mem+2))); //this one is at the position of the meta data for the second block, incrementing by two will bring it to proper data;

	printf("%f\n", *((double*)(mem+10)));

	printf("%f\n", *((double*)(mem+18)));

	printf("%f\n", *((double*)(mem+26)));
	
	printf("%f\n", *((double*)(mem+34)));

*/
	free(ptrInt);


	printf("size of PtrInt after free is %d and the state of PtrInt after free is %d\n", ((meta*)mem) -> size, ((meta*)mem) -> isfree);
	printf("%f\n", *(double*)(mem + 16 + 2*sizeof(meta)));
	printf("%f\n", ptrDouble[0]);
	printf("%f\n", ptrDouble[1]);
	printf("%f\n", ptrDouble[2]);
	printf("%f\n", ptrDouble[3]);	
	

	char* p = (char *)malloc( 200 );
	free( p + 10 );
	///Workloads
	//workLoad1();
	//workLoad2();

	

	return;


}
