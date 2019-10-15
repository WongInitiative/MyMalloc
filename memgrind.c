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

	char* ptr = (char *) malloc(1);
	printf("%x", ptr);

	int* ptrInt = (int *) malloc (4*sizeof(int));
	ptrInt[0] = 1;
	ptrInt[1] = 2;
	ptrInt[2] = 3;
	ptrInt[3] = 4;

	printf("%d", ptrInt[2]);
	printf("%d", *(ptrInt + 2));

	double* ptrDouble = (double *) malloc(5*sizeof(double));
	printf("%x", ptr);


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
	clock_t start, end;

	int count = -1;

	char* ptr[50];

	start = clock();
	while (count < 50){
		int number = rand();
		if (number % 2 == 0 && count == -1){
			continue;
		}
		else if (number % 2 == 0 && count >= 0) {
			free (ptr[count]);
  			count--;
		}
		else if (number % 2 == 1) {
			ptr[count] = (char *) malloc(1);
			count++;
		}

	}

	int i = 0;
	while(i < 50){
		free(ptr[i]);
		i++;
	}

	end = clock();

	double total_time = (double) (end - start)/CLOCKS_PER_SEC;

	printf("Time it took for this to occur: %lf", total_time);

}



void workLoad4(){
        clock_t start, end;

        void* ptr[50];
        int count = -1;
        int i = 0;

        start = clock();
        while (i < 50){
                int classifier = rand();
                if (classifier % 2 == 0 && count == -1) {
                        continue;
                }
                else if (classifier % 2 == 0 && count >= 0){
                        free (ptr[count]);
                }
                else if (classifier % 2 == 1){
                        int byteSize = rand();
                        if (byteSize >= 1 && byteSize <= 64){
                                ptr[i] = (void *) malloc(byteSize);
                                count++;
                        }
                }

        }

        end = clock();

        double total_time = (double) (end - start)/CLOCKS_PER_SEC;

        printf("Total Time for this to take is: %lf", total_time);


}

void workLoadUnique1(){


}

void workLoadUnique2(){


}
