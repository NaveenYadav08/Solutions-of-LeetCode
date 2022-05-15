// LINK  https://leetcode.com/problems/valid-permutations-for-di-sequence/

/// CODE 


class Solution {
public:
    int vis[201];
    long long int dp[202][202];
    int mod=1000000007;
    
    int util(string &s,int index,int prev){
        if(index==s.size()) return 1;
        
        if(dp[index][prev]!=-1) return dp[index][prev];
        
        long long int cnt=0;
        if(s[index]=='D'){
           for(int i=0;i<prev;i++){
               if(vis[i]==0){
                    vis[i]=1;
                    cnt+=(util(s,index+1,i))%mod;
                     vis[i]=0; // backtrack
                   
               }
           } 
        }
        else{
            for(int i=prev+1;i<=s.size();i++){
                if(vis[i]==0){
                    vis[i]=1;
                    cnt+=(util(s,index+1,i))%mod;
                    vis[i]=0;
                }
            }
        }
        return dp[index][prev]=cnt%mod;
        // dp [i][p] = number of valid permutations from index i of DID string to end with prev ele as prv
    }
    
    
    int numPermsDISequence(string s) {
        long long int cnt=0;
        
        memset(vis,0,sizeof(vis));
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<=s.size();i++){  // 0 to n
            vis[i]=1;
            // taking each as starting element
            cnt+=(util(s,0,i))%mod;
            vis[i]=0;
        }
        return cnt%mod;
    }
};
