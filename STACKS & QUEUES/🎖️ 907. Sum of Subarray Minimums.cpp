// https://www.youtube.com/watch?v=9-TXIVEXX2w

// https://leetcode.com/problems/sum-of-subarray-minimums/





class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        
        stack<int> s1,s2;
        int n = A.size();
        vector<int> ns(n), ps(n);
        for(int i=0;i<n;i++)
        {
          ns[i]=n-i-1;
          ps[i]=i;
        }
        
        for(int i=0;i<n;i++)
        {  
            // this state give ans 
            while(!s1.empty() and A[s1.top()]>A[i])
            {
                ns[s1.top()]=i-s1.top()-1;
                s1.pop();
            }
            s1.push(i); // push each time
        }
        
        
        for(int i=n-1;i>=0;i--)
        {  
            // this state give ans 
            while(!s2.empty() and A[s2.top()]>=A[i])
            {
                ps[s2.top()]=s2.top()-i-1;
                s2.pop();
            }
            s2.push(i); // push each time
        }
        
        long long ans = 0;
        long long mod=1e9+7;
        for(int i=0;i<n;i++)
        {
        ans = ans%mod + (((A[i])%mod)*((ps[i]+1)*(ns[i]+1))%mod);
        ans%=mod;
        
        }
        return (int)ans;
            
    }
};
