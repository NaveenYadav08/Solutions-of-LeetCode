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



  
