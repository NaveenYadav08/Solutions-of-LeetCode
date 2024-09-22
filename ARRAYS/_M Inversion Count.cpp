//GFG -  https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// I think there is no O(1) space solution for this.

// CODE -

class Solution{
  public:
    //Counter to keep the count of inversions.
    long long my_counter = 0;
    
    // p: initial point in the array, say left index
    // q: mid point
    // r: higher range
    //Function to sort and merge two parts of array.
    void merge(long long a[], long long p, long long q, long long r){
        long long l = q-p+1; // size of array
        long long a1[l];
    
        long long l2 = r-q; // size of array
        
        long long a2[l2];
        
        //Storing elements present in left half in the array a1.
        for(long long i = 0;i<l;i++){
            a1[i] = a[i+p];
        }
        //Storing elements present in right half in the array a2.
        for(long long i = 0;i<l2;i++){
            a2[i] = a[q+i+1];
        }
        
        long long left = 0, right = 0, k = p;
        
        //Using two pointers over the two arrays which helps in storing the
        //smaller element and thus merging the array.
        while(left < l && right < l2)
        {
            //Comparing element of the arrays a1 and a2 at pointers left and 
            //right and accordingly storing the smaller element and updating 
            //the pointers.
            if(a1[left] <= a2[right]){
                a[k] = a1[left];
                left++;
            }
            else{
                a[k] = a2[right];
                right++;
                //Adding the inversions which is the number of elements which 
                //are smaller than a2[right] in the a1 array.
                my_counter += (l-left); 
            }
            k++;
        }
        //Storing  the remaining elements of left subarray(if there are any)
        //in the array a1.
        while(left < l){
            a[k++] = a1[left++];
        }
        //Storing the remaining elements of right subarray(if there are any)
        //in the array a2.
        while(right < l2){
            
            a[k++] = a2[right++];
        }
    }

    //Function to mergesort the array, which uses divide and conquer algorithm
    //on left and right halves of array for mergesort operation.
    void mergeSort(long long a[], long long p, long long r)
    {   
        if(p>=r) return;
        
        
            long long q = (p+r)/2;
            //Calling recursive function to sort left half of the array.
            mergeSort(a, p, q);
            
            //Calling recursive function to sort right half of the array.
            mergeSort(a, q+1, r);
            
            //Calling merge function which sorts and merges both halves
            //of the array obtained after calling both recursive function.
            merge(a, p, q, r);
        
    }
    
    //Function to count inversions in the array.
    long long int inversionCount(long long arr[],long long N)
    {
        mergeSort(arr,0,N-1);
        long long int res = my_counter;
        my_counter = 0;
        //returning the count of inversions in the array.
        return res;
    }

};
