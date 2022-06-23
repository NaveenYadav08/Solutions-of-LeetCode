https://leetcode.com/problems/sequential-digits/

// Explanation :-

// Starting digit of number can be from 1 to 9 , so we will loop through it.
// Make a dfs call with parameters as low, high, i , 0(as initial number).
// Check if number lies in the range, push it in the vector.
// If i becomes greater than 9 or number goes out of range, return.
// Make a recursive call with i + 1 , num * 10 + i.
// Sort the vector and return.


class Solution {
public:
    vector<int> ans;
    void dfs(int low , int high , int i , int num){
        if(num >= low && num <= high){
            cout<<num<<endl;
            ans.push_back(num);
        }   
        if(i > 9 || num > high){
            return;
        }
        dfs(low , high , i + 1 , num * 10 + i);
    }
    
    vector<int> sequentialDigits(int low, int high) {
        for(int i = 1 ; i <= 9 ; i++){
            dfs(low , high , i , 0); // TAKING CURR AS STARTING DIGIT
            
        }
        sort(ans.begin() , ans.end());
        return ans;  
    }
};
