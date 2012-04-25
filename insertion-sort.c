#include <stdio.h>

void display(int a[], int n)
{
	int i;
	for (i=0; i<=n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

/* 
   Insert the first element from the unsorted array to 
   the correct position in the sorted array
*/
void insertion_sort(int a[], int n)
{
	int i, j, temp;
	for (i=1; i<=n ; i++) {
		for (j=i ; j>0 ; j--) {
			if (a[j] < a[j-1]) {
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
}

int main()
{
	int a[] = {9, 7, 2, 3, 5, 4, 1, 8, 6, 10};
	int n=9;
	
	insertion_sort(a, n);
	
	printf("Sorted array: \n");
	display(a, n);
	return 0;
}
