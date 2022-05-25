#include<stdio.h>
int main()
{
    int n=5;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=i;
    }
    for(int i=0;i<n;i++)
    {
        printf("P%d",arr[i]);
    }
}