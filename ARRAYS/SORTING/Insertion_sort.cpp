It is a stable sorting algorithm, meaning that elements with equal values 
maintain their relative order in the sorted output.


  Insertion sort is like sorting playing cards in your hands. 
  You split the cards into two groups: the sorted cards(left) and the unsorted cards(right).
  Then, you pick a card from the unsorted group and put it in the right place in the sorted group.

  Loop from i=1 to i<n, pick key = arr[i] and insert it into 
  sorted arr[0 .... i-1]
  

  TC == best O(N) and worst/avg = O(N^2)

Advantages of Insertion Sort:
    Simple and easy to implement.
    Stable sorting algorithm.
    Efficient for small lists and nearly sorted lists.
    Space-efficient.

Disadvantages of Insertion Sort:
    Inefficient for large lists.

Application = for small datasets.

  
// ITERATIVE // 
void insertionSort(int arr[], int n)
{

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key, 
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


//  RECURSIVE //
// Recursive function to sort an array using 
// insertion sort 
void insertionSortRecursive(int arr[], int n) 
{ 
    // Base case 
    if (n <= 1) 
        return; 
  
    // Sort first n-1 elements 
    insertionSortRecursive( arr, n-1 ); 
  
    // Insert last element at its correct position 
    // in sorted array. 
    int key = arr[n-1]; 
    int j = n-2; 
  
    /* Move elements of arr[0..i-1], that are 
    greater than key, to one position ahead 
    of their current position */
    while (j >= 0 && arr[j] > last) 
    { 
        arr[j+1] = arr[j]; 
        j--; 
    } 
    arr[j+1] = key; 
} 
