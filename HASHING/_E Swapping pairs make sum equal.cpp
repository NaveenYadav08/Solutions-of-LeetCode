// GFG - https://practice.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1

// CODE 

// We are looking for two values, a and b, such that: 
// sumA - a + b = sumB - b + a
//     2a - 2b  = sumA - sumB
//       a - b  = (sumA - sumB) / 2

// Therefore, we’re looking for two values that have a specific target difference: (sumA – sumB) / 2. 

class Solution{

	private:
	int getSum(int X[], int n)
	{
	    int sum = 0;
	    for (int i = 0; i < n; i++)
	        sum += X[i];
	    return sum;
	}
	 

	int getTarget(int A[], int n, int B[], int m)
	{

	    int sum1 = getSum(A, n);
	    int sum2 = getSum(B, m);
	 

	    if ((sum1 - sum2) % 2 != 0)
	        return INT_MIN;
	    return ((sum1 - sum2) / 2);
	}

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{

	    sort(A, A + n);
	    sort(B, B + m);
	 

	    int target = getTarget(A, n, B, m);
	 
	    if (target == INT_MIN)
	        return -1;
	 
	    int i = 0, j = 0;
	    while (i < n && j < m) 
	    {
	        int diff = A[i] - B[j];
	        if (diff == target) 
	        {
	            return 1;
	        }

	        else if (diff < target)
	            i++;

	        else
	            j++;
	    }
	    
	    return -1;
	}
 

};



// BETTER WITHOUT SORTING , LESS TC 

#include <bits/stdc++.h>
using namespace std;
void findSwapValues(int a[], int m, int b[], int n);
int main()
{
	int a[] = { 4, 1, 2, 1, 1, 2 }, b[] = { 1, 6, 3, 3 };
	int m, n;
	m = sizeof(a) / sizeof(int),
	n = sizeof(b) / sizeof(int);
	findSwapValues(a, m, b, n);
	return 0;
}


void findSwapValues(int a[], int m, int b[], int n)
{
	unordered_set<int> x,y; /* Unordered sets (and unordered maps) are
			                   implemented internally using hash tables; they
			                   support dictionary operations (i.e. search,
			                   insert, delete) in O(1) time on an average. */
	unordered_set<int>::iterator p, q;
	int s1, s2;
	int i;
	s1 = 0;
	for (i = 0; i < m; i++)       /* Determining sum s1 of the elements of array
				                  a[], and simultaneously inserting the array
				                 elements in the unordered set. */
		s1 += a[i], x.insert(a[i]);


	s2 = 0;
	for (i = 0; i < n; i++)
		s2 += b[i], y.insert(b[i]);

	if ((s1 - s2) % 2) /* Checking if difference between the
											two array sums
						                     is even or not. */
	{
		printf("No such values exist.\n");
		return;
	}

	for (p = x.begin(); p != x.end(); p++) {
		q = y.find(((s2 - s1) + 2 * *p)/ 2);   // Finding q for a given p in O(1) time.
		if (q != y.end()) {
			printf("%d %d\n", *p, *q);
			return;
		}
	}
	printf("No such values exist.\n");
}


