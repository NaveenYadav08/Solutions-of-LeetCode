Selection Sort 

Repeatedly selecting the smallest (or largest) element from the unsorted portion of the list 
and moving it to the sorted portion of the list. 

Selection Sort	O(n2)	O(n2)	O(n2) ALL CASES


Advantages of Selection Sort Algorithm
        Simple and easy to understand.
        Works well with small datasets.
Disadvantages of the Selection Sort Algorithm
        Selection sort has a time complexity of O(n^2) in the worst and average case.
        Does not work well on large datasets.
        Unstable Does not preserve the relative order of items with equal keys which means it is not stable.

// ITERATIVE //
void selectionSort(int arr[], int n)
{

    // One by one move boundary of
    // unsorted subarray
    for (int i = 0; i < n - 1; i++) {

        // Find the minimum element in
        // unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}


//  RECURSIVE //
void recurSelectionSort(int a[], int n, int index = 0)
{
    // Return when starting and size are same
    if (index == n)
       return;
 
    // calling minimum index function for minimum index // 
    // minidx from idx to last //
    int k = minIndex(a, index, n-1);
 
    // Swapping when index and minimum index are not same
    if (k != index)
       swap(a[k], a[index]);
 
    // Recursively calling selection sort function
    recurSelectionSort(a, n, index + 1);
}
