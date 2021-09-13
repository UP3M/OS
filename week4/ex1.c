#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int n = 69;
	pid_t x = fork();	

	if (x==0){
		printf("Hello from Child[%d-%d]\n", getpid(), n);
	}

	else if (x>0){
		printf("Hello from Parent[%d-%d]\n", getpid(), n);
	}
	else{
		return EXIT_FAILURE;
	}
    return EXIT_SUCCESS;
}
  