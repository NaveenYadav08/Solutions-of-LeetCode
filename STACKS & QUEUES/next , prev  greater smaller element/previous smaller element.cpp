// same as next smaller ele
// but traverse n-1 to 0

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        vector<int> ans(n);
        stack<int> s;
        
        
        // iterate st 
        for(int i=n-1;i>=0;i--)
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
