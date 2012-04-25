#include <stdio.h>

/*

Reference:
http://www.cise.ufl.edu/~ddd/cis3020/summer-97/lectures/lec17/sld001.htm

Divide (partition) and conquer (combine)

Given an array, say A[p..r], we need to partation this into two. Firstly, 
find a pivot element (it could be first element, last element, middle element,
random element, etc). Now, split the array into two in such a way that
 - All elements < pivot should be at the left side of the pivot
 - All elements > pivot should be at the right side of the pivot
 - At the end of the partition, pivot should be in its final position

			A[p..r]
		Pivot element - q
	A[p..q-1]  A[q]	 A[q+1..r]


Now recursively follow the above mentioned steps on two sub arrays,
A[p..q-1] and A[q+1..r]

partition algorithm is as follows:
Array:
{9, 7, 2, 3, 5, 4, 1, 8, 10, 6}
 ^                           ^
 p                           r

Now, let pivot be array[r], which is 6
pivot = 6

Now, take two variables, say up and down and assign the following:
up = p; 
down = r-1;

{9, 7, 2, 3, 5, 4, 1, 8, 10, 6}
 ^                       ^   ^
 up/p                  down  r

while (up <= down)
	while array[up] is < pivot 
		move up forward

	while array[down] is > pivot
		move down backwards
	
	// Here, up will contain the larger element in its sequence
	// and down will contatin the smaller element in its sequence
	// So, swap them (if up and down has not crossed each other)
	
	if up and down has not crossed each other
		swap array[up] with array[down]

// Here, at the end of the above while loop, 
// up and down would've crossed each other.
// now up will point to the first element which is > pivot and 
// down will point to the last element of the list which contains
// elements < pivot
// Now, swap array[up] with array[r] (where, r is pivot index)

swap array[up] with array[r]
return up;  // up is the index of the pivot element after partition
*/

int partition (int a[], int p, int r)
{
		// take pivot as the last element
		int pivot = a[r];
		int temp, i;
		int up = p, down = r-1;
	
		while(up <= down) {
			while (a[up] < pivot) 
				up++;
			while (a[down] > pivot)
				down--;
			if (up < down) {
				temp = a[up];
				a[up] = a[down];
				a[down] = temp;
			}

		}	
		temp = a[up];
		a[up] = a[r];
		a[r] = temp;
		
		/*
		for (i = 0; i < 10; i++)
				printf ("%d ", a[i]);
		printf ("\n");
		*/

		return up;
}


void qsort (int a[], int p, int r)
{
		int q;

		if (p < r) {
				q = partition (a, p, r);
				qsort (a, p, q-1);
				qsort (a, q+1, r);
		}
}


int main()
{
		//int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		int a[] = {9, 7, 2, 3, 5, 4, 1, 8, 6, 10};
		int i;

		qsort (a, 0, 9);

		for (i = 0; i < 10; i++)
				printf ("%d ", a[i]);

		printf ("\n");

		return 0;
}
