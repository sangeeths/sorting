#include <stdio.h>

void display(int a[], int n)
{
	int i;
	for (i=0; i<=n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

/* 
   greatest element goes to the last at the 
   end of the first iteration
*/
void bubble_high(int a[], int n)
{
	int i, j, temp;
	for (j=n-1; j>=0 ; j--) {
		for (i=0; i<j; i++) {
			if (a[i] > a[i+1]) {
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
		}
	}
	return;
}

/* 
   smallest element goes to the first at the 
   end of the first iteration
*/
void bubble_low(int a[], int n)
{
	int i, j, temp;
	for (i=n; i>=1; i--) {
		for (j=n; j>=n-i+1; j--) {
			if (a[j] < a[j-1]) {
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
	return;
}

int main()
{
	int a[] = {9, 7, 2, 3, 5, 4, 1, 8, 6, 10};
	int n=9;
	
	//bubble_high(a, n);
	bubble_low(a, n);
	
	printf("Sorted array: \n");
	display(a, n);
	return 0;
}
