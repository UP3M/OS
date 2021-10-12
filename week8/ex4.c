#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
#include <sys/resource.h>

int main(){
    int* ptr;
    int size = 10 * 1024 * 1024;//10mb = 10 * 2^20

    for(int i = 0; i < 10; i++){
        ptr = malloc(size);
        memset(ptr, 0, size);

        struct rusage mem;
        getrusage(getpid(), &mem);
        printf("Memory Usage \n in RAM: %ld, in Swap: %ld\n", mem.ru_maxrss, mem.ru_nswap);

        sleep(1);
        free(ptr);
    }

}
