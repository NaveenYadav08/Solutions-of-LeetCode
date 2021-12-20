// LEETCODE  https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/

// CODE 
// SLIDING WINDOW 


//this math will give me ki curr[i]  kitnae substrings mae unique hae , so hr us uniqueness ko add krte jao and we will reach to the final ans 
// let a = A ( just to resolve confusion )
// ABa 
// 121  left
// 222  right 
//ans = 2 + 4 + 2
// for A - A(1) , AB(2) 
//  for B - AB(2) , Ba(2), ABa(1), B(1)
// for a -  a(1) , Ba(2) 
//here for eg AB repeat 2 bcz it gives uniqueness of A and B both 


class Solution {
public:
    /*
        For each char str[i]..
        Find it's previous and next occurrence (left and right vectors)..
        Now this is the range where str[i] will be unique..
        So total number of substrings where str[i] will be unique = left[i] * right[i]

        NOTE: str[i] will be present in all (left[i] * right[i]) substrings because we are
              calculating length of the substring while always considering 'i', i.e. str[i].
    */
    int uniqueLetterString(string str) {        
        int n = str.size();
        vector<int> left(n,0), right(n,0);
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            int j=i-1;
            while(j>=0) {
                if(str[j] == str[i]) break;
                j--;
            }
            left[i] = i-j;
            
            j=i+1; ;
            while(j<n) {
                if(str[j] == str[i]) break;
                j++;
            }
            right[i] = j-i;
        }
        
        for(int i=0; i<n; i++) {
            ans += (left[i] * right[i]);
        }
        
        return ans;
    }
};
