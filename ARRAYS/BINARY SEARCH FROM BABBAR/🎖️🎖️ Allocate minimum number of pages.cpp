https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

class Solution 
{
    public:
    
    
//Function to find minimum number of pages.
int isPossible(int A[], int pages, int students, int N) {
  int cnt = 0;
  int sumAllocated = 0;
  for (int i = 0; i < N; i++) {
    if (sumAllocated + A[i] > pages) {
      cnt++;
      sumAllocated = A[i];
      if (sumAllocated > pages) return false;
    } else {
      sumAllocated += A[i];
    }
  }
  if (cnt < students) return true;
  return false;
}



int findPages(int A[], int N, int B) {
  if (B > N) return -1;
  int low = A[0];
  int high = 0;
  //to find minimum value and sum of all pages
  for (int i = 0; i < N; i++) {
    high = high + A[i];
    low = min(low, A[i]);
  }
  //binary search
  while (low <= high) {
    int mid = (low + high) >> 1;
    if (isPossible(A, mid, B, N)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low;
}


};
