#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_arr(int* arr, int size){
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
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
  printf("enter NewSize of N( for deallocate): ");
  scanf("%d", &M);

  int* temp = realloc(arr, M*sizeof(int));
  if(temp!=NULL)
  arr = temp;

 printf("%p\n", arr);
  print_arr(arr, M);

  free(arr);
  
  return 0;
}