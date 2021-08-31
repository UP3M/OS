
#include <stdio.h>

int main(int argc, char *argv[]) {
     
	int size;
    	if (argc >1){
   		sscanf(argv[1],"%d", &size);
	}

    for (int i=0; i < size; i++){
        for (int j=0; j < size - i - 1; j++){
            printf(" ");
        }
        for (int j=0; j < i*2 + 1; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}