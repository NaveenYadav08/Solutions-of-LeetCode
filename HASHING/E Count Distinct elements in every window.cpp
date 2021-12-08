// GFG - https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

// CODE 

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0;i<=k-1;i++)
        {
            m[A[i]]++;
        }
        ans.push_back(m.size());
        
        int start =0;
        int end=k-1;
        
        end++;
        while(end<n)
        {
            
            
            m[A[start]]--;
            if(m[A[start]]==0)
            m.erase(A[start]);
            
            start++;
            m[A[end]]++;
            ans.push_back(m.size());
            end++;
            
            
        }
        
        return ans;

    }
};
