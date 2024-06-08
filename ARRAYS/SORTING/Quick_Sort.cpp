QuickSort is a sorting algorithm based on the Divide and Conquer algorithm 
that picks an element as a pivot and partitions the given array around the picked pivot 
by placing the pivot in its correct position in the sorted array.


The key process in quickSort is a partition(). The target of partitions is to place the pivot
(any element can be chosen to be a pivot) at its correct position in the sorted array 
and put all smaller elements to the left of the pivot, 
and all greater elements to the right of the pivot.

Partition is done recursively on each side of the pivot 
after the pivot is placed in its correct position and this finally sorts the array.



  ALGORITHM
  1. Choose a pivot element from the array (typically the last element). 
  
  2. Partition the array into two sub-arrays: one containing elements less than the pivot, and the other containing elements greater than the pivot. 
  
  3. Recursively apply Quicksort to the sub-arrays. 
  
  4. Concatenate the sorted sub-arrays along with the pivot to form the final sorted array. 


Best/Average Case: Ω (N log (N))
    The best-case scenario for quicksort occur when the pivot chosen at the 
    each step divides the array into roughly equal halves.
Worst Case: O(N^2)
    The worst-case Scenario for Quicksort occur when the pivot at each step 
    consistently results in highly unbalanced partitions. 
    When the array is already sorted & the pivot is always chosen as the smallest or largest element. 
    To mitigate the worst-case Scenario, various techniques are used such as choosing a good pivot 
    using Randomized algorithm (Randomized Quicksort ) to shuffle the element before sorting.


Advantages of Quick Sort:
      It is efficient on large data sets.
      It has a low overhead, as it only requires a small amount of memory to function.
Disadvantages of Quick Sort:
      It has a worst-case time complexity of O(N2),
      It is not a good choice for small data sets.
      It is not a stable sort,
             because here we are swapping elements according to the pivot’s position 
             (without considering their original positions).


// ⭐⭐  RANDOM PARTITION ⭐⭐ //
    // finding the pivot element and partition the array along that
    int randomPartition(int arr[], int l, int r)
    {
        int n = r-l+1;
        int pivot = rand() % n;
        swap(&arr[l + pivot], &arr[r]);
        return partition(arr, l, r);
    }

// CODE //

int partition(int arr[],int low,int high)
{
  //choose the pivot
  
  int pivot=arr[high];
  //Index of smaller element and Indicate
  //the right position of pivot found so far
  int i=(low-1);
  
  for(int j=low;j<=high-1;j++)
  {
    //If current element is smaller than the pivot
    if(arr[j]<pivot)
    {
      //Increment index of smaller element
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return (i+1);
}

// The Quicksort function Implement
// low - 0, high - n-1
void quickSort(int arr[],int low,int high)
{
  // when low is less than high
  if(low<high)
  {
    // pi is the partition return index of pivot
    // it place the pi element at its correct place and
    // rec sort left and right.
    int pi=partition(arr,low,high);
    
    //Recursion Call
    //smaller element than pivot goes left and
    //higher element goes right
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}



  
