#include <stdio.h>
#include <stdlib.h>
#define Num_of_bit 16

struct frame{
  int id;
  unsigned counter : Num_of_bit;
}*frame;


int main (void){
	
	printf("Number of frames:\n");
	int frames;
	scanf("%d", &frames);
	
  frame=malloc(sizeof(frame)*frames);
  for(int i =0; i<frames;i++){
    frame[i].id=-1;
    frame[i].counter=0;
  }
	
	FILE *fp=fopen("file.txt", "r");
	int cur_pageRef=0;
  int candidate=0;
  double hit=0;
  double miss=0;
  

  while(fscanf(fp, "%d", &cur_pageRef)!=EOF){
    
    for(int i =0; i<frames;i++){
      printf("i=%d,\tid=%d,\tCounter: dec: %d\n ", i, frame[i].id, frame[i].counter);
    }
    printf("\ncurrent page reference: %d\n", cur_pageRef);
    unsigned tmp_counter = frame[0].counter;
    for(int i =0; i<frames;i++){
      frame[i].counter=frame[i].counter>>1;
      if(frame[i].id ==-1){
        candidate = i;
        break;
        }
      else if(frame[i].id == cur_pageRef){
        candidate = i;
        break;
        }
      else{
        if(frame[i].counter < tmp_counter){
          tmp_counter = frame[i].counter;
          candidate=i;
          }
        }
    }
    if (cur_pageRef==frame[candidate].id){
      frame[candidate].counter=frame[candidate].counter|(1<<(Num_of_bit-1));
      hit++;
    }
    else{
      frame[candidate].id=cur_pageRef;
      frame[candidate].counter=0;
      frame[candidate].counter=frame[candidate].counter|(1<<(Num_of_bit-1));
      miss++;
    }
  }
  for(int i =0; i<frames;i++){
      printf("i=%d,\tid=%d,\tCounter: dec: %d\n ", i, frame[i].id, frame[i].counter);
    }

	double ratio = hit/miss;
	printf("\nTotal hit %f, total miss %f, ratio %f", hit, miss, ratio);

	fclose(fp);
	free(frame);
	
	return 0;
}