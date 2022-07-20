https://practice.geeksforgeeks.org/problems/searching-in-an-array-where-adjacent-differ-by-at-most-k0456/1

// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k){
    
    int idx, i = 0;
    
    while(i < n){
        
        if(arr[i] == x) return i;
        
        int leap = abs(x-arr[i]) / k;
        
        leap == 0 ? i++ : i+=leap;
    }
    return -1;
}     	
