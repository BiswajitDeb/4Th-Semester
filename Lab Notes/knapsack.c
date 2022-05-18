#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of materials : ");
    scanf("%d", &n);
    float weight[n];
    float value[n];
    float max;
    float per_unit[n];

    printf("Enter the weights of the materials : \n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the weight of the %dth material : ",i);
        scanf("%f", &weight[i]);
        printf("Enter the value of the %dth material : ",i);
        scanf("%f", &value[i]);

        per_unit[i] = value[i]/weight[i];
    }
    printf ("Enter max capasity of the knapsack : ");
    scanf("%f",&max);
//sorting by per_unit value

int temp_unit;
int temp_weight;
int temp_value;
for(int i = 0; i < n-1; i++)
{
    for(int j = 0; j < n-i-1; j++)
    {
        if(per_unit[j]>per_unit[j+1])
        {
            temp_unit = per_unit[j];
            temp_weight = weight[j];
            temp_value = value[j];

            per_unit[j]=per_unit[j+1];
            weight[j]=weight[j+1];
            value[j]=value[j+1];


            per_unit[j+1]=temp_unit;
            weight[j+1]=temp_weight;
            value[j+1]=temp_value;

        }
    }
}

//selecting items
float profit=0;

while (max!=0)
{   
    int k=n-1;

    if(max < value[k])
    {
        profit += per_unit[k]*max;
        max=0;
    }
    else
    {
        max -= weight[k];
        profit += value[k];
        k--;

    }
    
}

    printf("The max profit possible is : %f",profit);


    return 0;
}
