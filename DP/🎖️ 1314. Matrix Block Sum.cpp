// LINK - https://leetcode.com/problems/matrix-block-sum/

// I am using aonother zero matrix and for each elemnet I am seeing its impact row

// NOW in each impact ROW , I am seeing their IMPACT COLUMNS ( only first and one beyond last ) 

// now add the element value at start col , and subtract element val from end + 1 col 

// it means when we traverse that row the element will keep adding till start to end , then as we add negative of it so 
// in cumilitave sum it will automatically subtract 

// CODE 

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
       
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>a(n,vector<int>(m,0)); // it is my new zero matrix        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int x=-k;x<=k;x++){ // it is for all the impact rows 
                    if(i+x>=0 && i+x<n){
                        
                        int l=max(j-k,0); // impact col start 
                        int r=j+k+1; // impact col end + 1

                        a[i+x][l]+=mat[i][j]; // add 
                        if(r<m) a[i+x][r]-=mat[i][j]; // subtract
                        
                       // UNcomment for seeing matrix each time after compute
                        // for(int I=0;I<n;I++)
                        // {
                        //     for(int J=0; J<m; J++)
                        //     {
                        //         cout<<a[I][J]<<"  ";
                        //     }
                        //     cout<<endl;
                        // }
                        // cout<<endl;
                    }
                }
            }
        }
        
        int sum=0;
        
        // cummulative sum of each row 
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=0;j<m;j++){
                sum+=a[i][j];
                a[i][j]=sum;
            }
        }
        return a;
    }
};
