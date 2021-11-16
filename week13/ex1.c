#include <stdio.h>
#include <stdlib.h>
#define M 3
#define N 5

int main()
{   //i is the index to write into array, size if length of our possible array
    int i , j;
    int E [M];
    int A [M];
    int C [N][M];
    int R [N][M];
    int temp [M];
    int mark [N];
    char blank[3];
    int counter =0;
    //Create a file pointer to open file
    FILE * fp;
    fp = fopen("input.txt","r");
    if (fp == NULL){
        printf("Error. Can't open the file\n");
        exit(1);
    }
    else {
      //fill up all arrays
      for (i = 0; i < M; i++){
          fscanf(fp,"%d",&E[i]);
      }
      fgets(blank, sizeof(blank), fp);
      for (i = 0; i < M; i++){
          fscanf(fp,"%d",&A[i]);
      }
      fgets(blank, sizeof(blank), fp);
      for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
          fscanf(fp,"%d",&C[i][j]);
          }
      }
      fgets(blank, sizeof(blank), fp);
      for (i = 0; i < N; i++){
        for (j=0; j< M; j++){
          fscanf(fp,"%d",&R[i][j]);
          }
      }
      //print the array
      printf("E= ");
      for (i = 0; i < M; i++){
          printf("%d ",E[i]);
      }
      printf("\nA= ");
      for (i = 0; i < M; i++){
          printf("%d ",A[i]);
      }
      printf("\nC= \n");
      for (i = 0; i < N; i++){
        for (j=0; j< M; j++){
          printf("%d ",C[i][j]);
        }
        printf("\n");
      }
      printf("R=\n");
      for (i = 0; i < N; i++){
        for (j=0; j< M; j++){
          printf("%d ",R[i][j]);
        }
        printf("\n");
      }
    }

    for (i = 0; i < N; i++){
          mark[i]=0;
      }
    int check = 1;
    while(check==1){
      check=0;
      for (i=0; i < N; i++){
        if (mark[i]==0){
          for (int k = 0; k<M; k++){
            temp[k] = A[k];
          }
          for (j=0; j<M; j++){
            int comp= A[j]+C[i][j];
            if(R[i][j]<=comp){
              temp[j]+=C[i][j];
              if (j==M-1){
                for (int k = 0; k<M; k++){
                  A[k] = temp[k];
                  C[i][k]=0;
                  }
                check=1;
                mark[i]=1;
              }
            }
            else
            break;
          }
        }
      }
    }
    
      for (i=0; i<N; i++){
        if(mark[i]==0){
        printf("process # %d deadlocked\n", i);
        counter ++;
        }
      }
      if (counter == 0)
      printf("no deadlock\n");
      printf("total number of deadlock = %d", counter);
    
}