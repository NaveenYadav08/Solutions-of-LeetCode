// MATHS OF 12th CLASSS
https://www.youtube.com/watch?v=wT7gcXLYoao

60. Permutation Sequence
https://leetcode.com/problems/permutation-sequence/



class Solution {
public:
    string getPermutation(int n, int k) {
        
        string ans="";
        vector<int> num;
        int fact=1;
        for(int i=1;i<n;i++)
        {
            fact=fact*i;
            num.push_back(i);
        }
        num.push_back(n);
        k=k-1;
        while(true)
        {
            ans+=to_string(num[k/fact]);
            num.erase(num.begin()+k/fact);
            if(num.size()==0)
                break;
            k=k%fact;
            fact=fact/num.size();
            
        }
        return ans;
           
    }
};
