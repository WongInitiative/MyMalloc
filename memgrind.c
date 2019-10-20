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

struct timeval start, end;

int main(int argc, char* argv[]){
	workLoad1();
	workLoad2();
	workLoad3();
	workLoad4();
	/*int a = 0;
	while (a <150){
		char * ptr = (char*) malloc(sizeof(char));
		printf("%d\n", ((meta*)mem) -> isfree);
		free (ptr);
		printf("%d\n", ((meta*)mem) -> isfree);
		a++;
	}
	*/
	return 0;	
}
/// malloc 1 byte and free immediately after
void workLoad1(){

	double total_time = 0;
	
	int a;
	for (a = 0; a < 100; a++){
		gettimeofday(&start,NULL);
		
		int b;
		for (b = 0; b < 150; b++){
			char* ptr = (char*) malloc(sizeof(char));
			free(ptr);
			a++;
		}
		gettimeofday(&end, NULL);

		total_time += (double) (end.tv_usec - start.tv_usec); 
		
	}	

	double avg_time = total_time/150;
	printf("average time it takes to malloc 150 times is %lf\n", avg_time);

	return;
}



///malloc 150 bytes; after 50 bytes free all of them
void workLoad2(){

	double total_time = 0;
	char* ptr[50];

	int a, b;

	for (a = 0; a < 100; a++) {
		gettimeofday(&start, NULL);
		
		int count = 0;
		while (count < 3){
			for (b = 0; b < 50; b++){
				ptr[b] = (char*) malloc(1);
			}
	
			for (b = 0; b <50; b++){
				free(ptr[b]);
			}
		count++;
		}

		gettimeofday(&end, NULL);
		
		total_time += (double)(end.tv_usec - start.tv_usec);
	}

	double avg_time = total_time / 100; //Time it takes to malloc and free an array of 50
	printf("average Time it took to malloc 50 ptrs then free all ptrs 3 times is: %lf\n", avg_time);
}


///Randomy choose between 1 byte malloc or freeing 1 byte free
void workLoad3(){
	double total_time = 0;
	char* ptr[50];

	int count = -1;

	int a;

	for(a = 0; a < 100; a++){
		gettimeofday(&start, NULL);

		while (count < 50){
			int number = rand();
			if (number % 2 == 0 && count == -1){ ///If we are trying to free from an array w/o any ptrs
				continue;
			} 
			else if (number % 2 == 0 && count >= 0){
				free(ptr[count]);
				count--;
			}
			else if (number % 2 == 1) {
				ptr[count] = (char *) malloc(1);
				count++;
			} 
		}

		int i = 0;
		while (i < 50){
			free(ptr[i]);
			i++;
		}

		gettimeofday(&end, NULL);
		total_time += (double) (end.tv_usec - start.tv_usec);
		
	}

	double avg_time = total_time / 100; 
	printf("average time it took to randomly choose between free and malloc, only freeing everything after 50 ptrs are malloced: %f\n", avg_time); 
	
}

///Randomly mallor or free byte arrays of any size within 1 ~ 64; once 50 of these r malloced free all and end
void workLoad4(){

	double total_time = 0;

	void * ptr[50];
	int count = -1;

	int a;
	for (a = 0; a < 100; a++){
		gettimeofday(&start, NULL);

		while (count < 50){
		
			int classifier = rand();
			if (classifier % 2 == 0 && count == -1){
				continue;
			}
			else if (classifier % 2 == 0 && count >= 0){
				free(ptr[count]);
				count--;
			}
			else if (classifier % 2 == 1){
				int byteSize = rand();
				if (byteSize >= 1 && byteSize <= 64){
					ptr[count] = (void *) malloc(byteSize);
					count++;
				}
			}

		}

		gettimeofday(&end, NULL);
		total_time += (double)(end.tv_usec - start.tv_usec);	

	}

	double average_time = total_time / 100;
	printf("average time to randomly malloc or free byte arrays of any size within 1 to 64 bytes is: %lf", average_time);
	

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
