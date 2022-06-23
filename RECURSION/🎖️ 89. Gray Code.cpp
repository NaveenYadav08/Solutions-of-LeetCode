https://leetcode.com/problems/gray-code/

class Solution {
public:
    
bool isPowerOfTwo(int n)
{
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}
    
    bool backtrack(vector<int> &result, unordered_set<int> &added_ints, int n) {
        if (result.size() == 1 << n) {
            int test_one_bit = result.back() ^ result.front();
            return (isPowerOfTwo(test_one_bit));
        }
        
        for (int i = 0; i < n; ++i) {
            int next = (1 << i) ^ result.back(); // us no ki hr bit ko flip kra mene
            if (added_ints.find(next) == added_ints.end()) { // if not found
                result.push_back(next);
                added_ints.insert(next);
                if (backtrack(result, added_ints, n)) {
                    return true;
                }
                added_ints.erase(result.back());
                result.pop_back();
            }
        }
        return false;
    }

    vector<int> grayCode(int n) {
        vector<int> result(1, 0);
        unordered_set<int> added_ints({0});
        backtrack(result, added_ints, n);
        return result;
    }
};
