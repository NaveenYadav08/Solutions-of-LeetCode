https://leetcode.com/problems/permutations-ii/

class Solution {
  public:
 

  
  void helper(vector<int>& S, vector<vector<int>>& ans, int i, int n)
	{
	    if(i==n)
	    {
	        ans.push_back(S);
	        //cout<<S<<"  print"<<endl;
	        return;
	    }
	    if(i>n)
	    return;
	    
	    unordered_set<int> s;
	    for(int k=i;k<n;k++)
	    {
	       if(s.find(S[k])!=s.end())
	        continue;
	        s.insert(S[k]);
	        swap(S[i],S[k]);
	        helper(S,ans,i+1,n);
	        swap(S[i],S[k]);
	    }
	}
  
    vector<vector<int>> uniquePerms(vector<int> S ,int n) {
        // code here
        vector<vector<int>> ans;
         helper(S,ans,0,S.size());
         sort(ans.begin(),ans.end());
        return ans;
    }
};



// class Solution {
// public:
//     vector<vector<int>>ans;//to store final ans
//     void solve(vector<int> nums,int idx)
//     {
//         if(idx==nums.size())//if idx equals arr size add current permutation to ans
//         {
//             ans.push_back(nums);
//         }
//         for(int i=idx;i<nums.size();i++)
//         {
//             if(i!=idx && nums[i]==nums[idx])//to cheak if the elements are duplucate 
//                 continue;
//             swap(nums[i],nums[idx]);//swap the current element with the index
//             solve(nums,idx+1);//solve for next index
            
//         }
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         sort(nums.begin(),nums.end());//sort the given array
//         solve(nums,0);
//         return ans;
        
//     }
// };
