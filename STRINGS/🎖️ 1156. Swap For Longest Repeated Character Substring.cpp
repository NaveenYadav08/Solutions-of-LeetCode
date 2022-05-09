// link https://leetcode.com/problems/swap-for-longest-repeated-character-substring/

// code 
class Solution {
public:
    int maxRepOpt1(string text) {
        
        unordered_map<char,int> freq;
        
        for(auto ch:text)
        {
            freq[ch]++;
        }
        
        
        int ans = INT_MIN;
        
        
        // I will try to replace with each char
        for(char ch ='a'; ch<=('z'); ch++)
        {  
            if(freq.find(ch)==freq.end())
            continue;
         
            if(freq[ch]==text.size())
                return text.size();
            
         int curr=0; int pre=0; int sum=0; int i=0;
         while(i<text.size())
         {
             if(text[i]==ch)
             {
                 
                 curr++;
                 
             }
             else
             {
                 sum=pre+curr;
                 sum+=(sum<freq[ch])?1:0;
                 //cout<<sum<<endl;
                 pre=curr;
                 curr=0;
                 ans=max(ans,sum);
                
                 
                 
             }
             i++;
         }
         
                 sum=pre+curr;
                 sum+=(sum<freq[ch])?1:0;
                 ans=max(ans,min(sum,freq[ch]));
         
         
         
              
        }
        
        return ans;
        
        
        
    }
};
