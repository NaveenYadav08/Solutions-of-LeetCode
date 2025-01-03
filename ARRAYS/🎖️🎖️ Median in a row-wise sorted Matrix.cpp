 R and C are always odd
 
 https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#
 


Approach 2: Efficient Approach (Using Binary Search)

Step 1: Find the minimum and maximum element in the given array. 
  By just traversing the first column, we find the minimum element and by just traversing the last column, we find the maximum element.

Step 2: Now find the middle element of the array one by one and check in the matrix how many elements are present in the matrix.

Three cases can occur:-

If count ==  (r*c+1)/2 , so it may be the answer still we mark max as mid since we are not referring indices , 
we are referring the elements and 5 elements can be smaller than 6 also and 7 also , so to confirm we mark max as mid.
If count<(r*c+1)/2 , we mark  min as mid+1 since curr element or elements before it cannot be the answer.
If count>(r*c+1)/2 , we mark max as mid , since elements after this can only be the  answer now.
  
 
 NO of elements less than or equl to x
  
  
  
  CODE --
  
  class Solution {

public:
    int median(vector<vector<int>> &matrix, int r, int c)
    {
        int min = INT_MAX, max = INT_MIN;
        for (int i = 0; i < r; i++)
        {
            if (matrix[i][0] < min)
                min = matrix[i][0];
     
            if (matrix[i][c-1] > max)
                max = matrix[i][c-1];
        }
     
        int desired = (r * c + 1) / 2;
        
        while (min < max)
        {
            int mid = min + (max - min) / 2;
            int place = 0;
            for (int i = 0; i < r; ++i)
                place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            if (place < desired)
                min = mid + 1;
            else
                max = mid;
        }
        return min;
    }
};


// CODE - 2 //
int countSmallerThanMid(vector<int> &row, int mid)
{
  int l = 0, h = row.size() - 1;
  while (l <= h)
  {
    int md = (l + h) >> 1;
    if (row[md] <= mid)
    {
      l = md + 1;
    }
    else
    {
      h = md - 1;
    }
  }
  return l;
}

int median(vector<vector<int>> &A, int R, int C)
{
  int low = 1;
  int high = 1e9;
  int n = A.size();
  int m = A[0].size();
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      cnt += countSmallerThanMid(A[i], mid);
    }
    if (cnt <= (n * m) / 2)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}

  
  
