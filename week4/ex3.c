#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char command[100];
	char exit[] = "exit";
	for(;;){
		printf("enter command:");
		scanf("%s", command);
		if (strcmp (command, exit)==0){
			return EXIT_SUCCESS;
		}
		else
		system(command);
	}
}