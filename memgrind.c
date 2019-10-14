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


	///Workloads
	workLoad1();
	workLoad2();



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
