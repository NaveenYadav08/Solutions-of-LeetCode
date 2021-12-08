// LEETCODE - https://leetcode.com/problems/majority-element-ii/submissions/

// CODE -

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int num1=-1;
        int num2=-1;
        int count1=0;
        int count2=0;
        for(auto x:nums)
        {
            if(x==num1)
                count1++;
            else if(x==num2)
                count2++;
            else if(count1==0)
            {
               count1=1;
                num1=x;
            }
            else if(count2==0)
            {
                count2=1;
                num2=x;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        
        int cc1=0;
        int cc2=0;
        for(auto x:nums)
        {
            if(x==num1)
                cc1++;
            else if(x==num2)
                cc2++;
        }
        
        vector<int> vv;
        
        if(cc1>nums.size()/3)
            vv.push_back(num1);
        if(cc2>nums.size()/3)
            vv.push_back(num2);
        return vv;
        

        
        
        
    }
};
