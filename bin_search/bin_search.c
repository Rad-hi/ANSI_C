/*
	PAGE: 54
	---
	Our binary search makes two tests inside the loop, when one 
	would suffice (at the price of more tests outside.) Write 
	a version with only one test inside the loop and measure 
	the difference in run-time.
	---
	This code contains both the book example and my approach,
	and they both define the same function prototype.
		-> Uncomment whichever option you wanna run
 */

#include <stdio.h>
#include <time.h>

/* Uncomment the option you want to run */
//#define TEST_BOOK_EXAMPLE
#define TEST_OWN_EXAMPLE

/* Just to make sure not both are defined at the same time -> throw an error */
#if (defined(TEST_BOOK_EXAMPLE) && defined(TEST_OWN_EXAMPLE))
	#error "TEST_BOOK_EXAMPLE and TEST_OWN_EXAMPLE can't be both defined. Comment one of them!"
#endif

/* Number of elements in the table to be searched */
#define NUM_ELEMENTS			8

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */ 
int binsearch(int x, int v[], int n);

int main(){

	clock_t begin = clock();

	const int x = 34;
	int v[NUM_ELEMENTS] = {12, 15, 16, 18, 22, 34, 39, 45};

	int position = binsearch(x, v, NUM_ELEMENTS);

	printf("FOUND IT AT: %d\n", position + 1);

	/* Calculate runtime */
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("TOOK: %.8f s TO RUN\n", time_spent);

	return 0;
}


#ifdef TEST_BOOK_EXAMPLE
	
	int binsearch(int x, int v[], int n){
		int low, high, mid;
		low = 0;
		high = n - 1;
		while (low <= high) {
			mid = (low+high)/2;
			if (x < v[mid])
				high = mid + 1;
			else if (x > v[mid])
				low = mid + 1;
			else /* found match */
				return mid;
		}
		return -1; /* no match */
	}

#elif defined(TEST_OWN_EXAMPLE)
	
	int binsearch(int x, int v[], int n){
		int low, high, mid;
		low = 0;
		high = n - 1;

		while (low <= high){
			mid = (low+high)/2;

			if(v[mid] == x)
				return mid;

			/*  Didn't find the solution the book hinted for \_(°~°)_/
				so opted for a branchless approach, and they both almost perform
				the same (runtime wise)
			 */
			high = high * (x > v[mid]) + (x < v[mid])*(mid + 1);
			low = low * (x < v[mid]) + (x > v[mid])*(mid + 1);
		}

		return -1; /* no match */
	}

#endif