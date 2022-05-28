https://leetcode.com/problems/single-number-iii/


260. Single Number III

class Solution {
public:
    
    
    // BASICAALLY Sbka xor krdo 
    
    // xor = a^b  only uniques 
    
    
    // is xor ki lsb nikali base on this 
    // divided all nos into two set 1 jisme wo lsb set hae else nhi hae 
    
    // uske baad set a ka xor is 1 ans
    // set 2 ka xor is ans 2
    
    vector<int> singleNumber(vector<int>& nums) {
        int val = 0; 
        for (auto& x : nums) val ^= x; 
        
        int i=0;
        int t=val;
        while(abs(t)>0)
        {  //cout<<"HHIHHI"<<endl;
           if(t&(1)) 
               break;
           t=t/2;
            i++;
               
        }
        
        // cout<<(1<<i)<<endl;

        
            
        // cout<<val<<endl;
        // cout<<i<<endl;
        int I = (1<<i);
        // cout<<I<<endl;
        
        int a=0;
        int b=0;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]&(I))
                a^=nums[j];
            else
                b^=nums[j];
        }
        
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
        
        
    }
};
