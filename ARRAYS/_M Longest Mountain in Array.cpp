// LEETCODE - https://leetcode.com/problems/longest-mountain-in-array/

// CODE -
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int res=0;
        int n=arr.size();
        if(n<3)
            return res;
        for(int i=1;i<n;i++)
        {
            int count=1;
            bool flag=0;
            int j=i;
            while(j<n and arr[j]>arr[j-1])
            {
                j++ ;
                count++;
            }
            // dec seq;
            while(i!=j and j<n and arr[j]<arr[j-1])
            {
                j++;
                count++;
                flag=true;
            }
            
            if(i!=j and flag and count>2)
            {
                res=max(res,count);
                cout<<j<<endl;
                j--;
            }
            
            i=j;
            
        }
        
        return res;
        
    }
};
