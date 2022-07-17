https://practice.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1

class Solution{
    public:
int  solve(vector<vector<char>>&mat,string &target,int x,int y,int index,vector<vector<int>>&vis){
       int n=mat.size();
       int m=mat[0].size();
      
       if(x<0||x>=n||y<0||y>=m||mat[x][y]!=target[index]||vis[x][y]==1){
           return 0;
       }
       if(index==target.size()-1){
               return 1;
       }
       int ans=0;
       vis[x][y]=1;
       vector<int> dir={-1,0,1,0,-1};
       for(int i=0;i<4;i++){
           int newx=x+dir[i];
           int newy=y+dir[i+1];
           if(newx>=0&&newx<n&&newy>=0&&newy<m&&vis[newx][newy]==0){
               ans+=solve(mat,target,newx,newy,index+1,vis);
           }
       }
       vis[x][y]=0;
       return ans;
   }
   
   int findOccurrence(vector<vector<char> > &mat, string target){
       int n=mat.size();
       int m=mat[0].size();
       int count=0;
       vector<vector<int>> vis(n,vector<int>(m,0));
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(mat[i][j]==target[0]){
                   count+=solve(mat,target,i,j,0,vis);
               }
           }
       }
       return count;
   }
};
