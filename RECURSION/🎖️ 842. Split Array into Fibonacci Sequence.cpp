https://leetcode.com/problems/split-array-into-fibonacci-sequence/



class Solution {
    vector<int> ans;
public:
    
    bool isvalid(string s){
        if(s[0]=='0'){
            if(s.size()==1) return true;
            return false;
        }
        return true;
    }
    bool fun(string s,long long int a,long long int b,vector<int> te){
        if(s.size()==0){
            if(te.size()<3){
                return false;
            }
            else{
                ans=te;
                return true;
            }
        }
        long long int val=0;
        for(int i=0;i<s.size();i++){
            val=val*10+(s[i]-'0');
            if(val>INT_MAX){
                break;
            }
            if(val<=INT_MAX && isvalid(s.substr(0,i+1)) && (val==(a+b) || (a==-1 || b==-1))){
                
                te.push_back(val);
                if(fun(s.substr(i+1),b,val,te)){
                    return true;
                }
                te.pop_back();
            }
        }
        return false;
    }
    
    
    vector<int> splitIntoFibonacci(string S) {
        vector<int> temp;
        long long a1=-1,a2=-1;
        fun(S,a1,a2,temp);
        for(auto a:ans){
            cout<<a<<" ";
        }
        return ans;
    }
};
