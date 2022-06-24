https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

class Solution {
private:
    
bool isUnique(string &s1){
        vector<int>check(26,0);
        for(int i=0;i<s1.size();i++){
            if(check[s1[i]-'a']==0){
                check[s1[i]-'a']++;
            } else {
                return false;
            }
        }
        return true;
    }
    
    
void backtrack(int &ans,vector<string>&arr,string curr,int index){
    
        if(index==arr.size()){
            int len=curr.size();
            ans=max(ans,len); return;
        } else {
            vector<bool>cnds={true,false};

                
                    string tmp=curr+arr[index];
                    if(isUnique(tmp)){
                        backtrack(ans,arr,tmp,index+1);
                    
                } 
                    backtrack(ans,arr,curr,index+1);
                
            
        }
    }
    
    
public:
    
    
int maxLength(vector<string>& arr) {
        int ans=0;
        backtrack(ans,arr,"",0);
        return ans;
    }
};
