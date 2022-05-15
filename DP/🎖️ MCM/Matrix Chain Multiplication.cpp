Matrix Chain Multiplication
Given a sequence of matrices, find the most efficient way to multiply these matrices together.

  at end the ans matrix will be same 
However, the order in which we parenthesize the product affects the number of simple arithmetic operations needed to compute the product.
For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then,  

(AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.
  
  // CODE 
  

#include <bits/stdc++.h>
using namespace std;
int dp[100][100];

// Function for matrix chain multiplication
int matrixChainMemoised(int* p, int i, int j)
{
	if (i == j)
	{
		return 0;
	}
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
  
	dp[i][j] = INT_MAX;
  
  // k is for partittion
  // after partitionn left = i to k , right k + 1 to j
  // why k go from i to j-1 bcz if go till j no one left in right of it
  // and the two parts formed are  A[i-1]*A[k]
  // A[k]*A[j]
	for (int k = i; k < j; k++)
	{
		dp[i][j] = min(dp[i][j], matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
	}
	return dp[i][j];
}


int MatrixChainOrder(int* p, int n)
{
	int i = 1, j = n - 1;
  

	return matrixChainMemoised(p, i, j);
}

// Driver Code
int main()
{
	int arr[] = { 1, 2, 3, 4 };
  // this arr has 3 matrix , matrix i = arr[i]*arr[i-1] , A = 1*2
	int n = sizeof(arr) / sizeof(arr[0]);
	memset(dp, -1, sizeof dp);

	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(arr, n);
}


