// https://leetcode.com/problems/maximum-product-of-word-lengths/


318. Maximum Product of Word Lengths



/// by this 
// I convert tring into bit like abcdefghijklmnopqrstuvwzyz   1 us jagae jo jo lettter ismaae hae 
class Solution {

    // TC : O(n2)
    // SC : O(n)
    public:
    int maxProduct(vector<string>& words) {

        int len = words.size();
        vector<int> state(len);


        for (int i=0; i<len; i++) {

            state[i] = getStateFromString(words[i]);

        }

        int maxProduct = 0;
        for (int i = 0; i < len; i++)
            for (int j = i + 1; j < len; j++) {
                if ((state[i] & state[j]) == 0) {
                    if(words[i].length() * words[j].length() > maxProduct) {
                        maxProduct = words[i].length() * words[j].length();
                    }
                }
            }
        return maxProduct;
    }

    private:
    int getStateFromString(string s){
        int state = 0;
        for(auto c:s){
            int index = c  -'a';
            state |= 1 << (index);
        }
        return state;
    }
};
