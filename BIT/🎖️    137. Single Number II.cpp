https://leetcode.com/problems/single-number-ii/




137. Single Number II




class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ANS=0;
        for(int i=0;i<32;i++)
        {   int ans=0;
            for(int j=0; j<nums.size(); j++)
            {
                ans+=((nums[j])&(1<<i))?1:0;
                //cout<<ans<<endl;
            }
         //cout<<"ANS  "<<ANS<<endl;
         ANS =  ANS+((ans%3)<<i);
        }
        return ANS;
        
    }
};
