Repetedly keep swapping elements if they are in wrong order. 
  in ascending we shift max element to last.

Complexity Analysis of Bubble Sort:
  Time Complexity: O(N^2), Best TC = O(N)
  Auxiliary Space: O(1)

Advantages of Bubble Sort:
      Bubble sort is easy to understand and implement.
      It does not require any additional memory space.
      It is a stable sorting algorithm, meaning that elements with the same key value maintain their relative order in the sorted output.

Disadvantages of Bubble Sort:
      Bubble sort has a time complexity of O(N2) which makes it very slow for large data sets.

Used with Small Datasets or Nearly Sorted Data: 


// ITERATIVE APPROACH
      void bubbleSort(int arr[], int n) {
        // Your code here
        for(int i=0;i<n-1;i++)
        {   bool flag = true;
            for(int j=0;j<n-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {swap(arr[j],arr[j+1]); flag = false;}
            }
            if(flag==false) break;
        }
    }

// Recursive Approach
void bubbleSort(int arr[], int n) 
{ 
    // Base case 
    if (n == 1) 
        return; 

    int count = 0; 
    // One pass of bubble sort. After 
    // this pass, the largest element 
    // is moved (or bubbled) to end. 
    for (int i=0; i<n-1; i++) 
        if (arr[i] > arr[i+1]){ 
            swap(arr[i], arr[i+1]); 
            count++; 
        } 
  
      // Check if any recursion happens or not 
      // If any recursion is not happen then return 
      if (count==0) 
           return; 
  
    // Largest element is fixed, 
    // recur for remaining array 
    bubbleSort(arr, n-1); 
} 
