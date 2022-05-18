#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	clock_t start, end, total;

	int n;
	printf("Enter the no. of activities:\n");
	scanf("%d",&n);

	int st_t[n], en_t[n];

	for(int i = 0; i < n; i++) {
		printf("Enter the starting time of activity %d: ",(i+1));
		scanf("%d",&st_t[i]);

		printf("Enter the ending time of activity %d: ",(i+1));
		scanf("%d",&en_t[i]);
	}

	//sorting the both the arrays wrt end time 
	
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < n - i - 1; j++) {
			if(en_t[j] > en_t[j+1]) {
				int t = en_t[j];
				en_t[j] = en_t[j + 1];
				en_t[j + 1] = t;

				t = st_t[j];
				st_t[j] = st_t[j + 1];
				st_t[j + 1] = t;
			}
		}
	}

	// getting the time limit
	int lm;
	printf("\nEnter the time limit:");
	scanf("%d",&lm);

	int elapsed = 0;
	int c = 0, count = 0;
	
	start = clock();	
	while(elapsed < lm) 
	{
		elapsed = en_t[c];
		count++;
		printf("Activity %d is selected.\n",(c+1));

		for(int i = c + 1; i < n; i++) {
			int x = st_t[i];
			if(x >= elapsed) {
				c = i;
				break;
			}
		}

	}
	end = clock();
	total = (int)(end - start);

	printf("The number of activities within the time period is: %d.\n",count);
	printf("The time taken for the algorithm is: %ld ms.\n",total);
	return 0;
}