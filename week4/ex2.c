 #include <stdio.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <stdlib.h>

 #define N 5
int main(){
  for(int i=0;i<N;++i){
    fork();  
    sleep(5);  
  }
  return EXIT_SUCCESS;
}