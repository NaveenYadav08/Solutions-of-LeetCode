https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1/

// iterate 0 to n-1
// going to push index
// while(!s.empty and arr[s.top()]>arr[i]) // to us s.top ka ans i hoga
//{ ans[s.top()] =arr[i]
//s.pop();
//}

// s,push(i) // each time

// at the end of fot  iteration for all index left in stack ans is -1



class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        vector<int> ans(n);
        stack<int> s;
        // iterate st 
        for(int i=0;i<n;i++)
        {  
            // this state give ans 
            while(!s.empty() and arr[s.top()]>arr[i])
            {
                ans[s.top()]=arr[i];
                s.pop();
            }
            s.push(i); // push each time
        }
        
        while(!s.empty())
        {
            ans[s.top()]=-1;
            s.pop();
        }
        return ans;
        
    } 
};
