#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>

//memset(ptr, 0, size) is used to swaps ("si" (swap-ins) and "so" (swap-outs)). after memset is removed, there is no swap especially on "so"
int main(){
    int* ptr;
    int size = 10 * 1024 * 1024;//10mb = 10 * 2^20
    //the size could be different depending on the computer
    for(int i = 0; i < 10; i++){
        ptr = malloc(size);
        memset(ptr, 0, size);
        sleep(1);
        printf("Run %d\n", i+1);
        free(ptr);
    }

}