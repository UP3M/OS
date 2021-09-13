// ex 4 by oka resia
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	char command[100];
	char *NewCommand[100];
	char exit[] = "exit";
	int size =0;
	for(;;){
		scanf("%[^\n]%*c", command);
		if (strcmp (command, exit)==0){
			return EXIT_SUCCESS;
		}
		else{
			char *token = strtok(command, " ");
			while(token!=NULL){
			    NewCommand[size] = token;
				token = strtok(NULL, " ");
				size++;
			}
			NewCommand[size]= NULL;
			
			
			pid_t x = fork();	
			if (x==0){
				if(size==1){
					system(command);
				}else 
				execvp(NewCommand[0], NewCommand);
				}
			for(int i=0; i<size+1; i ++){
						NewCommand[i]=NULL;
					}
					size=0;
		}
	}
}