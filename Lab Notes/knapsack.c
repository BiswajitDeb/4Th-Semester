#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of Jobs : ");
    scanf("%d", &n);
    float weight[n];
    float value[n];
    int max;
    float per_unit[n];

    printf("Enter the weights of the materials : ");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the weight of the %dth material : ",i);
        scanf("%f", &weight[i]);
        printf("Enter the value of the %dth material : ",i);
        scanf("%f", &value[i]);

        per_unit[i] = value[i]/weight[i];
    }

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

while (max!=0)
{   
    int j=n-1;
    if(max < value[j])
    {
        
    }
    
}



    printf("Enter maximum capacity : ");
    scanf("%d", &max);


    return 0;
}