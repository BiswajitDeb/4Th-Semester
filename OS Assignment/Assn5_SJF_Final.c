#include <stdio.h>

void sort_by_Burst(int n, int Process[][4] )
{
	for (int i = 0; i < n; i++) 
    {
		int temp;
		for (int j = i + 1; j < n; j++)
			if (Process[j][1] < Process[i][1])
				i = j;
		temp = Process[i][1];
		Process[i][1] = Process[i][1];
		Process[i][1] = temp;

		temp = Process[i][0];
		Process[i][0] = Process[i][0];
		Process[i][0] = temp;
	}
	Process[0][2] = 0;
}

void Waiting(int n,int Process[][4],int total_wait,float avg_waiting)
{
	for (int i = 1; i < n; i++) {
		Process[i][2] = 0;
		for (int j = 0; j < i; j++)
			Process[i][2] += Process[j][1];
		total_wait += Process[i][2];
	}
    // printf("Total Wait : %d",total_wait);
}

void TurnAround(int n,int Process[][4],int total_turn,float avg_Turn_Around)
{
	for (int i = 0; i < n; i++) {
		Process[i][3] = Process[i][1] + Process[i][2];
		total_turn += Process[i][3];
	}
    // printf("Total Turn around : %d",total_turn);
}

void sort_by_process(int n,int Process[][4])
{
    int temp_id,temp_burst,temp_wait,temp_turn;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(Process[j]>Process[j+1])
            {
                temp_id=Process[j][0];
                Process[j][0]=Process[j+1][0];
                Process[j+1][0]=temp_id;

                temp_burst=Process[j][1];
                Process[j][1]=Process[j+1][1];
                Process[j+1][1]=temp_burst;

                temp_wait=Process[j][2];
                Process[j][2]=Process[j+1][2];
                Process[j+1][2]=temp_wait;

                temp_turn=Process[j][3];
                Process[j][3]=Process[j+1][3];
                Process[j+1][3]=temp_turn;
            }
        }
    }
}

void display(int n, int Process[][4])
{
    printf("Process	 Burst Time\t\tWaiting Time\t\tTurn Around Time\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d \t\t %d \t\t %d	\t\t %d\n", Process[i][0],Process[i][1], Process[i][2], Process[i][3]);
    }
}

int main()
{
	int n, total_wait = 0,total_turn=0;
	float avg_waiting, avg_Turn_Around;
	printf("Enter number of process: ");
	scanf("%d", &n);
    int Process[n][4]; //Process[][0]=id , Process[][1] = Burst , Process[][2] = Waiting , Process[][3] = TurnAround

	for (int i = 0; i < n; i++) {
		printf("Enter Burst Time for P%d : ", i + 1);
		scanf("%d", &Process[i][1]);
		Process[i][0] = i + 1;
	}
	
    sort_by_Burst(n,Process);
	
    Waiting(n,Process,total_wait,avg_waiting);
	

    TurnAround(n,Process,total_turn,avg_Turn_Around);
    

    sort_by_process(n,Process);
    avg_waiting = total_wait / n;
    avg_Turn_Around = total_turn / n;   
	
    display(n,Process);
	
	printf("Average Waiting Time : %d", total_wait);
	printf("\nAverage Turnaround Time : %d", total_turn);
}
