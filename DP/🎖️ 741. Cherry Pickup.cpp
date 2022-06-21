https://leetcode.com/problems/cherry-pickup/

class Solution {
public:
      // BACKTRACKING SOLUTION BUT IT'LL GIVE TLE AS WE ARE EXPLORING ALL POSSIBLE WAYS
     // RECURSIVE AND MEMOIZED SOLUTION 
    // Instead of sending one person to end and again back to origin we send to person together 
    // and collect all the cherries on the way
    
    int dp[51][51][51][51];
    
    int cp(int r1,int c1,int r2,int c2,vector<vector<int>>& arr){
        
     // base case
    if(r1>=arr.size() || c1 >=arr[0].size() || r2>=arr.size() || c2 >=arr[0].size() || 
        arr[r1][c1]==-1 || arr[r2][c2]==-1)  return INT_MIN;
        
        // when any one reaches destination then also only one cherry will be counted
         if(r1==arr.size()-1 && c1==arr.size()-1) return arr[r1][c1];
               
        if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];
        int cherries=0;
        // if both the persons are on same point on arr
 
        if(r1==r2 && c1==c2) cherries+=arr[r1][c1]; // only one cherry will be counted
        else
            cherries+=arr[r1][c1]+arr[r2][c2];
        
        int f1 = cp(r1, c1+1, r2, c2+1, arr); // h, h
        int f2 = cp(r1+1, c1, r2, c2+1, arr); // v, h
        int f3 = cp(r1+1, c1, r2+1, c2, arr); // v, v
        int f4 = cp(r1, c1+1, r2+1, c2, arr); // h, v
        
        cherries+=max({f1,f2,f3,f4});
        
        return dp[r1][c1][r2][c2]=cherries;
        
    }
    
    int cherryPickup(vector<vector<int>>& arr) {
        if(arr.size()==1 && arr[0][0]==1) return 1;
         // int maxi=0;
        // solve(0,0,arr,0,maxi);
        // return maxi;
        
        memset(dp,-1,sizeof(dp));
        int finalCherries=cp(0,0,0,0,arr);
        return finalCherries < 0 ? 0:finalCherries;
    }

};
