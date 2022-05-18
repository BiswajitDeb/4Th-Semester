#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int *arr, int p, int r);
int partition(int *arr, int p, int r);

int main() {
	clock_t start, end, total;

	int n;
	printf("Enter the length of the array: ");
	scanf("%d",&n);
	
	int arr[n];
	
	for(int i = 0; i < n; i++) {
		arr[i] = (rand() % (100 - 0 + 1)) + 0;
	}
	
	printf("The array: \n");
	for(int i = 0; i < n; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	
	start = clock();
	
	quickSort(arr, 0, n - 1);
	
	end = clock();
	
	
	printf("The sorted array: \n");
	for(int i = 0; i < n; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	total = (int)(end - start);
	printf("The time taken : %ld ms\n",total);
	
	return 0;
}

void quickSort(int *arr, int p, int r) {
	if(p < r) {
		int q = partition(arr, p, r);
		quickSort(arr, p, q - 1);
		quickSort(arr, q + 1, r);
	}
}

int partition(int *arr, int p, int r) {
	//pivot
	int x = arr[r];
	int i = p - 1;
	for(int j = p; j < r; j++) {
		if(arr[j] <= x) {
			i++;
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}
	int t = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = t;
		
	return (i + 1);
}