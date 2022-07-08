https://leetcode.com/problems/circular-permutation-in-binary-representation/


class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int>temp(1<<n),ans(1<<n);
        int ind=0;
        for(int i=0;i<(1<<n);i++){
            temp[i]=i^(i>>1);  /// this is gray code imp
            
            // this store the index of start given
            if(temp[i]==start){
                ind=i;
            }
        }
        
  
            
        int I=ind;
        int i=0;
        for(;I<(1<<n);I++){
            ans[i++]=temp[I];
        }
        

        for(int j=0;j<ind;j++)
            ans[i++]=temp[j];
        return ans;
    }
};
