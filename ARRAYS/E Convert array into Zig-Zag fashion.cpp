// GFG - https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1

// CODE -
class Solution{
public:	
	// Program for zig-zag conversion of array
	void zigZag(int arr[], int n) {
	    // code here
	    int flag=0;
	    for(int i=0;i<n-1;i++)
	    {
	        if(flag==0)
	        {
	            if(arr[i]>arr[i+1])
	            {
	                swap(arr[i],arr[i+1]);
	            }
	        }
	        else
	        {
	            if(arr[i]<arr[i+1])
	            {
	                swap(arr[i],arr[i+1]);
	            }
	        }
	        
	        flag=1-flag;
	        
	    }
	}
};
