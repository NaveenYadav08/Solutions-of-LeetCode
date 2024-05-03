// WAY ALPHA //
    void mergeInPlace(vector<int>& nums,int start,int mid, int end) {
        int total_len = end - start +1;
        int gap = total_len/2 + total_len%2;
        while(gap>0) {
            int i = start, j = start + gap;
            while(j<=end) {
                if(nums[i]>nums[j]) {
                    swap(nums[i], nums[j]);
                }
                i++,j++;
            }
            gap = gap<=1 ? 0 : gap/2 + gap%2;
        }
    }

    void mergeSort(vector<int>& nums, int start, int end) {
        if(start>=end) return;
        int mid = (start+end)/2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        mergeInPlace(nums, start,mid,end);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }


-------------------------------------------------------------


// WAY - 1
// GAP METHOD
// CODE 
// Time Complexity: O(log n*nlog n)

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Calculating next gap
int nextGap(int gap)
{
	if (gap <= 1)
		return 0;
		
	return (int)ceil(gap / 2.0);
}

// Function for swapping
void swap(int nums[], int i, int j)
{
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

// Merging the subarrays using shell sorting
// Time Complexity: O(nlog n)
// Space Complexity: O(1)
void inPlaceMerge(int nums[], int start,int end)
{
	int gap = end - start + 1;
	
	for(gap = nextGap(gap);
		gap > 0; gap = nextGap(gap))
	{
		for(int i = start; i + gap <= end; i++)
		{
			int j = i + gap;
			if (nums[i] > nums[j])
				swap(nums, i, j);
		}
	}
}

// merge sort makes log n recursive calls
// and each time calls merge()
// which takes nlog n steps
// Time Complexity: O(n*log n + 2((n/2)*log(n/2)) +
// 4((n/4)*log(n/4)) +.....+ 1)
// Time Complexity: O(logn*(n*log n))
// i.e. O(n*(logn)^2)
// Space Complexity: O(1)
void mergeSort(int nums[], int s, int e)
{
	if (s == e)
		return;

	// Calculating mid to slice the
	// array in two halves
	int mid = (s + e) / 2;

	// Recursive calls to sort left
	// and right subarrays
	mergeSort(nums, s, mid);
	mergeSort(nums, mid + 1, e);
	
	inPlaceMerge(nums, s, e);
}

// Driver Code
int main()
{
	int nums[] = { 12, 11, 13, 5, 6, 7 };
	int nums_size = sizeof(nums) / sizeof(nums[0]);
	
	mergeSort(nums, 0, nums_size-1);
	
	for(int i = 0; i < nums_size; i++)
	{
		cout << nums[i] << " ";
	}
	return 0;
}

// This code is contributed by adityapande88





// WAY 2
// store 2 value in one 
// Time Complexity: O(n log n)
// CODE 


// C++ program in-place Merge Sort
#include <bits/stdc++.h>
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
// Inplace Implementation
void mergeInPlace(int a[], int l, int m, int r)
{
	// increment the maximum_element by one to avoid
	// collision of 0 and maximum element of array in modulo
	// operation
	int mx = max(a[m], a[r]) + 1;

	int i = l, j = m + 1, k = l;
	while (i <= m && j <= r && k <= r) {

		// recover back original element to compare
		int e1 = a[i] % mx;
		int e2 = a[j] % mx;
		if (e1 <= e2) {
			a[k] += (e1 * mx);
			i++;
			k++;
		}
		else {
			a[k] += (e2 * mx);
			j++;
			k++;
		}
	}

	// process those elements which are left in the array
	while (i <= m) {
		int el = a[i] % mx;
		a[k] += (el * mx);
		i++;
		k++;
	}

	while (j <= r) {
		int el = a[j] % mx;
		a[k] += (el * mx);
		j++;
		k++;
	}

	// finally update elements by dividing with maximum
	// element
	for (int i = l; i <= r; i++)
		a[i] /= mx;
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {

		// Same as (l + r) / 2, but avoids overflow
		// for large l and r
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		mergeInPlace(arr, l, m, r);
	}
}

// Driver Code
int main()
{
	int nums[] = { 12, 11, 13, 5, 6, 7 };
	int nums_size = sizeof(nums) / sizeof(nums[0]);

	mergeSort(nums, 0, nums_size - 1);

	for (int i = 0; i < nums_size; i++) {
		cout << nums[i] << " ";
	}
	return 0;
}


