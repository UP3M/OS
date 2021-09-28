
#include<stdio.h>

void swap(int *a, int*b)
{
	int temp  = *a;
	*a = *b;
	*b = temp;
}

void sorting(int processes[], int n, int bt[], int at[])
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
					swap(&processes[j], &processes[j+1]);
				}
			}
		}
}

void findWaitingTime(int processes[], int n,
		int bt[], int wt[], int at[])
{
	int s_time[n];
	s_time[0] = at[0];
	wt[0] = 0;

	for (int i = 1; i < n ; i++ ){
		s_time[i]= s_time[i-1] + bt[i-1];
		wt[i] = s_time[i] - at[i] ;
		if(wt[i]<0)
			wt[i] = 0;
		}
}

void findTurnAroundTime( int processes[], int n,
				int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}

void findavgTime( int processes[], int n, int bt[], int at[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	//Function to find waiting time of all processes
	findWaitingTime(processes, n, bt, wt, at);

	//Function to find turn around time for all processes
	findTurnAroundTime(processes, n, bt, wt, tat);

	//Display processes along with all details
	printf("Id Arrival Burst Waiting Turn around Completion time\n");

	// Calculate total waiting time and total turn
	// around time
	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		int completion_time = tat[i] + at[i];
		printf(" %d ",processes[i]);
		printf("	 %d ", at[i] );
		printf("	      %d ", bt[i] );
		printf("	 %d",wt[i] );
		printf("	      %d",tat[i] );
		printf("	      %d\n",completion_time );
	}
	float s=(float)total_wt / (float)n;
	float t=(float)total_tat / (float)n;
	printf("Average waiting time = %f",s);
	printf("\n");
	printf("Average turn around time = %f ",t);
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
	for(int i = 0; i<n; i++){
		int k = i+1;
		processes[i]= k;
		//Burst time of all processes
		printf("Enter Arrival time of process id %d: ", k);
		scanf("%d", &arrival_time[i]);
		printf("Enter Burst time of process id %d: ", k);
		scanf("%d", &burst_time[i]);
		}

	sorting(processes, n, burst_time, arrival_time);

	findavgTime(processes, n, burst_time, arrival_time);
	return 0;
}

