Selection Sort 

Repeatedly selecting the smallest (or largest) element from the unsorted portion of the list 
and moving it to the sorted portion of the list. 

Selection Sort	O(n2)	O(n2)	O(n2) ALL CASES

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
