#include <stdio.h>

void display(int a[], int n)
{
	int i;
	for (i=0; i<=n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

/* 
1. count the number of appearance of the all the elements
   present in the unsorted array.
2. Now go over the count array and print the elements for 
   count times (index) 

O(n) time to traverse the array to build the count array
O(k) space for storing the count, where k is number of 
	 unique elements in the the given array

sorting:
O(k) for going over the count array and O(n) for traversing 
the final array to write the elements in the sorted array
so its O(kn) time complexity
*/
void counting_sort(int a[], int n)
{
	int i, j=0;
	int count[10] = {0};
	for (i=0; i<=n ; i++)
		count[a[i]]++;

	printf("Count array: \n");
	display(count, n);

	for (i=0; i<=n ; i++) {
		while (count[i]) {
			a[j++] = i;
			count[i]--;
		}
	}
}

int main()
{
	int a[] = {0, 0, 2, 3, 5, 4, 1, 8, 6, 0};
	int n=9;
	
	counting_sort(a, n);
	
	printf("Sorted array: \n");
	display(a, n);
	return 0;
}
