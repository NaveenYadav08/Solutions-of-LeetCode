// LINK https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/


// CODE 


// The question can be converted into the form of Jump Game II.

// The range each tap covers is: max(0, i-ranges[i]) (say l) to min(n, i+ranges[i]) (say r). Think of this range as a jump starting from the index max(0,i-ranges[i]) with maximum reach till min(n, i+ranges[i]) - max(0, i-ranges[i]).
    
// To do this, we define a new array jumps where jumps[l] = max(jumps[l], r-l). Now our problem boils down to calculating the minimum number of jumps required to reach the end of array.
    
// The main idea is based on greedy. Lets say the range of the current jump is [curBegin, curEnd], curFarthest is the farthest point that all points in [curBegin, curEnd] can reach. Once the current point reaches curEnd, then trigger another jump, and set the new curEnd with curFarthest, then keep the above steps.

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
       
        vector<int> nums(n+1, 0);
        
        for (int i=0; i<ranges.size(); i++) {
            int l = max(0, i-ranges[i]);
            int r = min(n, i+ranges[i]);
            nums[l] = r-l;
        }
        
        // for (auto i : nums)
        //     cout<<i<<" ";
        // cout<<endl;
        
        // See Jump Game II
        int currReach = 0;
        int currMax = 0;
        int jumps = 0;
        
        for(int i=0;i<nums.size()-1; i++)
        {   if(i>currMax) return -1;
         
            if(i+nums[i]>currMax)
            {
                currMax=i+nums[i]; 
                // it will see all the jump between i and reach to see the max possibilty 
            }
            
            if(i==currReach)
            {// when I reach at currReach i will take the jump and update new reach as maxreach 
                jumps++;
                currReach = currMax;
            }

        }
        
        return currMax >= n ? jumps : -1;
        
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
