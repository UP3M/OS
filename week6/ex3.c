
#include<stdio.h>
void funct(int NOP, int quantum, int process[], int temp[], int at[], int bt[]){
 int T = at[0];
int counter = NOP;
	int wt[NOP];
	int tat[NOP];

    int done = 0;
    while (counter > 0){
        done = 0;
        for (int i = 0; i < NOP; i++){
            if (T >= at[i] && temp[i] > 0){
                done++;
                if (temp[i] > quantum){
                    T += quantum;
                    temp[i] -= quantum;
                }
                else{
                    T += temp[i];
                    wt[i] = T - bt[i] - at[i];
			tat[i]= bt[i]+wt[i];
                    temp[i] = 0;
                    counter -= 1;
                    break;
                } 
            }
        }
        if (done == 0)
            T++;
    }

printf("Id Arrival Burst Waiting Turn around Completion time\n");
int total_wt=0, total_tat=0;
for (int i=0; i<NOP; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		int completion_time = tat[i] + at[i];
		printf(" %d ",process[i]);
		printf("	 %d ", at[i] );
		printf("	      %d ", bt[i] );
		printf("	 %d",wt[i] );
		printf("	      %d",tat[i] );
		printf("	      %d\n",completion_time );
	}
	float s=(float)total_wt / (float)NOP;
	float t=(float)total_tat / (float)NOP;
	printf("Average waiting time = %f",s);
	printf("\n");
	printf("Average turn around time = %f ",t);
}  

void swap(int *a, int*b)
{
	int temp  = *a;
	*a = *b;
	*b = temp;
}

void sorting(int processes[], int n, int bt[], int tbt[], int at[])
{
	int i, j;
	for (i=0; i<n-1; i++)
		{
			for(j=0; j<n-i-1; j++)
			{
				if(at[j]>at[j+1])
				{
					swap(&at[j], &at[j+1]);
					swap(&bt[j], &bt[j+1]);
					swap(&tbt[j], &tbt[j+1]);
					swap(&processes[j], &processes[j+1]);
				}
			}
		}
}


// Driver code
int main()
{
	//process id's
	int n;
	printf("Enter number of process: ");
	scanf("%d", &n);
	int burst_time[n];
	int arrival_time[n];
	int processes[n];
	int temp_bt[n];
	int quant;
	for(int i = 0; i<n; i++){
		int k = i+1;
		processes[i]= k;
		//Burst time of all processes
		printf("Enter Arrival time of process id %d: ", k);
		scanf("%d", &arrival_time[i]);
		printf("Enter Burst time of process id %d: ", k);
		scanf("%d", &burst_time[i]);
		temp_bt[i]=burst_time[i];
		}

	sorting(processes, n, burst_time, temp_bt, arrival_time);
	printf("\nEnter the Time Quantum for the process: ");  
	scanf("%d", &quant);  

	funct(n, quant, processes, temp_bt, arrival_time, burst_time);
	return 0;
}


  