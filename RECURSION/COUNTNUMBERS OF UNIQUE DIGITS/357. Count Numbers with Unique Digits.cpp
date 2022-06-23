https://leetcode.com/problems/count-numbers-with-unique-digits/

class Solution {
public:
    int count(int n)
    {
        int ans=1,k=9;
        for(int i=1;i<=n;i++)
        {
            ans*=k;
            if(i!=1)
                k--;
        }
        return ans;
    }
    
    
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        if(n==1)
            return 10;
        int ans=10;
        for(int i=2;i<=n;i++)        
            ans+=count(i);
        return ans;        
    }
};
