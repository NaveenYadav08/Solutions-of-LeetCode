same as coding ninja but diff is last line ko exclude kro 

https://practice.geeksforgeeks.org/problems/word-wrap1646/1   SAME Q ONLY DIFF EXCLUDE ANS OF LAT LINE 


CODE 


class Solution {
public:

int calculateCost(int word, int line, vector<int> &wordsLength, vector<vector<int>> &dp, int &m)
{
    // Here, vector<int> wordsLength is storing the length of words.
    int n = wordsLength.size();
    if (word == n)
    {
        return 0;
    }

    // This 2 Dimensional DP array dp[word][line] indicates the
    // cost to put words from index word to line in a single line.
    if (dp[word][line] != -1)
    {
        return dp[word][line];
    }

    int ans = 1000000000;
    int current = 0;
    
    for (int w = word; w <= n - 1; w++)
    {   
        // Here we are making sure that we don't cross the maximum limit m.
        if (current + wordsLength[w] <= m)
        {
            // After pushing this word(wordsLength[w]) in the line, we will be updating the line's capacity.
            current += wordsLength[w] + 1;
            
            // The variable cost is the cost calculated till now till now .
            int cost = m - current + 1;
         
            // The variable ans2 is the cost if we move to the next line on this word only.
            if(w < n-1)
            {
                int ans2 = cost * cost  + calculateCost(w + 1, line + 1, wordsLength, dp, m);
                if (ans > ans2)
              {
                ans = ans2;
              }
            }
            else
                ans=0;

        }
        else break;

    }

    return dp[word][line] = ans;
}








    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n=nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = calculateCost(0, 0, nums, dp, k);
        return ans;
    } 
};

