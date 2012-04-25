#include <stdio.h>

#define MAXVAL 10 
int a[MAXVAL] = {10, 2, 4, 1, 5, 9, 7, 6, 8, 3};
int n = MAXVAL-1;

void heapify(int i, int size)
{
		int left = 2*i;
		int right = 2*i + 1;
		int max = i;
		int temp;

		if (left > size) return;

		if (right > size) {
				if (a[left] > a[max]) 
						max = left;
		} else {

				if (a[left] > a[max]) {
						max = left;
				} 

				if (a[right] > a[max])
						max = right; 
		}
		if (max != i) {
				temp = a[max];
				a[max] = a[i];
				a[i] = temp;
				heapify(max, size);
		}
}

void build_heap(int size)
{
	int i;
	
	for (i=size/2; i>=0 ; i--)
		heapify(i, size);

	return;
}

int main()
{
	int i, temp, j;
	
	printf("Before Heap\n");	
	for (i=0; i<MAXVAL; i++)
		printf("%d ", a[i]);
	printf("\n");

	build_heap(n);
	for (i=n ; i>0 ; i--) {
		// swapping the max value to the last 
		// element of the array
		temp = a[0];
		a[0] = a[i]; 
		a[i] = temp;
	
		n--;
		heapify(0, n);
	}
	

	printf("After Heap\n");	
	for (i=0; i<MAXVAL; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
