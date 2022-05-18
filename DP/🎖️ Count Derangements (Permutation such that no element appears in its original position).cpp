 // link  https://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/

#include <bits/stdc++.h>
using namespace std;

int countDer(int n)
{
// DP
	int der[n + 1] = {0};

	// Base cases
	der[1] = 0;
	der[2] = 1;

	// Fill der[0..n] in bottom up manner
	// using above recursive formula
	for (int i = 3; i <= n; ++i)
		der[i] = (i - 1) * (der[i - 1] +der[i - 2]);
  
  // it is because suppose I put 0 to position of 2 and 2 to position of 0 = n - 2 ele left
  
  // else if i only put 0 at some other position and not swapped that pst ele n - 1 ele left

	// Return result for n
	return der[n];
}

// Driver code
int main()
{
	int n = 4;
	cout << "Count of Derangements is "
		<< countDer(n);
	return 0;
}
