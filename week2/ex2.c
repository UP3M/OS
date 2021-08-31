#include <stdio.h>
#include <string.h>


void swap(){
    char string[100];

    printf("Enter your string: ");
    scanf("%s", string);
	printf("Reverse of your string: ");

    for (int i = strlen(string)-1; i>=0; i--){
        printf("%c", string[i]);
    }
}

int main() {
    swap();
    return 0;
}