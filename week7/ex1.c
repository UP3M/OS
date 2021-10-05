#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_arr(int* arr, int size){
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}


//ex 4
// newsize: number of element
void* Realloc(void* ptr, int newsize){
  int N = newsize* sizeof(int);
  int M = sizeof(ptr);
  if(ptr==NULL)
    return malloc(N);
  if(N == 0){
    free(ptr);
    return NULL;
  }else{
    if (N > M){
      void* temp= malloc(N);
      if(temp!=NULL){
        memcpy(temp, ptr, N);
        return temp; 
      } 
    }else {
      return ptr;
    }
  }
  return NULL;
}

int main(void) {
  int N;
  int M;

  int* arr = malloc(10 * sizeof(int));
  printf("enter N: ");
  scanf("%d", &N);
  for(int i =0; i<N; i++)
  arr[i]=i;

  printf("%p\n", arr);
  print_arr(arr, N);
  printf("enter NewSize of N: ");
  scanf("%d", &M);

//ex4
  int* temp2 = Realloc(arr, M);
  if(temp2!=NULL)
  arr = temp2;

  printf("%p\n", arr);
  print_arr(arr, M);
  free(arr);
  
  return 0;
}