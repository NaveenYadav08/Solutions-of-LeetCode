https://leetcode.com/problems/beautiful-arrangement/

class Solution {
public:
    
    bool helper(vector<int>& arr, int &count , int i)
    {
        if(i==arr.size())
            return true;
        
        for(int j=i; j<arr.size(); j++)
        {
            if(arr[j]%(i+1)==0  or ((i+1)>=arr[j]  and (i+1)%arr[j]==0))
            {
                swap(arr[i],arr[j]);
                if(helper(arr,count,i+1)==true) count++;
                swap(arr[i],arr[j]);
            }
            
        }
        return false;
    }

    
    int countArrangement(int n) {
        
        int count=0;
        int i=0;
        vector<int> arr;
        for(int I=0;I<n;I++)
            arr.push_back(I+1);
        
        helper(arr, count, i);
        return count;
        
    }
    
    
};
