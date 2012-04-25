#include <stdio.h>

void display(int a[], int n)
{
	int i;
	for (i=0; i<=n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

/* 
   select the smallest element from the unsorted list and 
   insert it to the last location in the sorted list
*/
void selection_sort(int a[], int n)
{
	int i, j, min, temp;
	for (i=0; i<=n ; i++) {
		min = i;
		for (j=i+1 ; j<=n ; j++) {
			if (a[j] < a[min])
				min = j;
		}
		if (min != i) {
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
}

int main()
{
	int a[] = {9, 7, 2, 3, 5, 4, 1, 8, 6, 10};
	int n=9;
	
	selection_sort(a, n);
	
	printf("Sorted array: \n");
	display(a, n);
	return 0;
}
