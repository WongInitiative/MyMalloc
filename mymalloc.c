#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv){

	int n = 0;
	if (n < 10){
        printf("working!!");
        n++;

        int j = 0;
        if (j < 10){
            printf("Working2!");
            j++;
        }
	}

	return 0;
}

