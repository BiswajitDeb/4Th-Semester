#include<stdio.h>

void display_unsorted(int n, int Arrival_time[],int Burst_time[],int Process[])
{
    printf("Process\t\tArrival Time\t\tBurst Time\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d\t\t%d\t\t\t%d\n",Process[i]+1,Arrival_time[i],Burst_time[i]);
    }
}

void Sorting(int n,int Arrival_Time[],int Burst_time[],int Process[])
{
    int temp_arrival;
    int temp_burst;
    int temp_value;
    int temp_process;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(Arrival_Time[j]>Arrival_Time[j+1])
            {
                temp_arrival = Arrival_Time[j];
                Arrival_Time[j]=Arrival_Time[j+1];
                Arrival_Time[j+1]=temp_arrival;
    
                temp_burst = Burst_time[j];
                Burst_time[j]=Burst_time[j+1];
                Burst_time[j+1]=temp_burst;

                temp_process=Process[j];
                Process[j]=Process[j+1];
                Process[j+1]=temp_process;
    
            }
        }
    }

}

void completion_time (int n, int Arrival_Time[],int Burst_Time[],int Completion_Time[])
{
    Completion_Time[0]=Arrival_Time[0]+Burst_Time[0];
    for(int i=1;i<n;i++)
    {
        Completion_Time[i]=Burst_Time[i]+Completion_Time[i-1];
    }

}

void Turn_Around(int n,int Arrival_time[],int Completion_Time[],int Turn_around_Time[])
{
    for(int i=0;i<n;i++)
    {
        Turn_around_Time[i]=Completion_Time[i]-Arrival_time[i];
    }
}

void Waiting(int n,int Turn_around_Time[],int Burst_time[],int Waitine_Time[])
{
    for(int i=0;i<n;i++)
    {
        Waitine_Time[i]=Turn_around_Time[i]-Burst_time[i];
    }
}

void display_sorted(int n, int Arrival_time[],int Burst_time[],int Completion_Time[],int Turn_around_Time[],int Waiting_Time[],int process[])
{
    printf("Process\t\tArrival Time\t\tBurst Time\t\tCompletion Time\t\tTurn Around Time\t\tWaiting Time\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d\n",process[i]+1,Arrival_time[i],Burst_time[i],Completion_Time[i],Turn_around_Time[i],Waiting_Time[i]);
    }
}

void Sorting_by_process(int n, int Arrival_time[],int Burst_time[],int Completion_Time[],int Turn_around_Time[],int Waiting_Time[],int process[])
{
    int temp_arrival;
    int temp_burst;
    int temp_value;
    int temp_process;
    int temp_waiting,temp_Completion,temp_turn_around;

    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(process[j]>process[j+1])
            {
                temp_arrival = Arrival_time[j];
                Arrival_time[j]=Arrival_time[j+1];
                Arrival_time[j+1]=temp_arrival;
    
                temp_burst = Burst_time[j];
                Burst_time[j]=Burst_time[j+1];
                Burst_time[j+1]=temp_burst;

                temp_process=process[j];
                process[j]=process[j+1];
                process[j+1]=temp_process;
    
                temp_Completion=Completion_Time[j];
                Completion_Time[j]=Completion_Time[j+1];
                Completion_Time[j+1]=temp_Completion;

                temp_waiting=Waiting_Time[j];
                Waiting_Time[j]=Waiting_Time[j+1];
                Waiting_Time[j+1]=temp_waiting;

                temp_turn_around=Turn_around_Time[j];
                Turn_around_Time[j]=Turn_around_Time[j+1];
                Turn_around_Time[j+1]=temp_turn_around;

            }
        }
    }

}

float waiting_time(int n,int waiting[],int turn_around[])
{
    int sum_waiting=0,sum_turn_around=0;
    // float avg_wait,avg_turn;
    for(int i=0;i<n;i++)
    {
        sum_waiting+=waiting[i];
        sum_turn_around+=turn_around[i];
    }
    return (sum_waiting/n),(sum_turn_around/n);
}

int main()
{
    int n;
    printf("Enter no of processes : ");
    scanf("%d",&n);
    int Burst_time[n];
    int Arrival_time[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter Arrival time of process p%d : ",i+1);
        scanf("%d",&Arrival_time[i]);
        printf("Burst time of process P%d : ",i+1);
        scanf("%d",&Burst_time[i]);
    }

    //process array
    int Process[n];
    for(int i=0;i<n;i++)
    {
        Process[i]=i;
    }

    //printing given processes
    printf("The Given processes Details : \n");
    display_unsorted(n,Arrival_time,Burst_time,Process);
    //sorting given processes
    Sorting(n,Arrival_time,Burst_time,Process);
    //display_unsorted(n,Arrival_time,Burst_time);

    //Completion time array 
    int Completion_Time[n];
    int Turn_around_Time[n];
    int Waiting_Time[n];
    
    completion_time(n,Arrival_time,Burst_time,Completion_Time);
    Turn_Around(n,Arrival_time,Completion_Time,Turn_around_Time);
    Waiting(n,Turn_around_Time,Burst_time,Waiting_Time);
    
    // printf("Completion time : ");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ",Completion_Time[i]);
    // }
    // printf("\nTurn Around Time : \n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ",Turn_around_Time[i]);
    // }
    // printf("\nWaiting Time : \n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ",Waiting_Time[i]);
    // }
    Sorting_by_process(n, Arrival_time,Burst_time,Completion_Time,Turn_around_Time,Waiting_Time,Process);
    display_sorted(n, Arrival_time,Burst_time,Completion_Time,Turn_around_Time,Waiting_Time,Process);
    printf("Average Waiting time : %d %d",waiting_time(n,Waiting_Time,Turn_around_Time));
    


    return 0;
}