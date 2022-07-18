https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1


code 


class Solution {
public:
	bool search(vector<vector<char>>grid,int i,int j,int idx,string word,string dir){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()|| grid[i][j]!=word[idx])
          return false;
          if(idx==word.size()-1)
          return true;
    
          bool found=false;
          if(dir=="n")
          found=search(grid,i-1,j,idx+1,word,"n");
          
          else if(dir=="s")
          found=search(grid,i+1,j,idx+1,word,"s");
          
          else if(dir=="e")
          found=search(grid,i,j+1,idx+1,word,"e");
          
          else if(dir=="w")
          found=search(grid,i,j-1,idx+1,word,"w");
          
          else if(dir=="ne")
          found=search(grid,i-1,j+1,idx+1,word,"ne");
          
          else if(dir=="nw")
          found=search(grid,i-1,j-1,idx+1,word,"nw");
          
          else if(dir=="se")
          found=search(grid,i+1,j+1,idx+1,word,"se");
          
          else if(dir=="sw")
          found=search(grid,i+1,j-1,idx+1,word,"sw");
          
          return found;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>>ans;
	    for(int i=0;i<grid.size();i++){
	        for(int j=0;j<grid[0].size();j++){
	            bool flag=false;
	            if(grid[i][j]==word[0]){
	                bool n= search(grid,i,j,0,word,"n");    //north
	                bool s= search(grid,i,j,0,word,"s");    //south
	                bool e= search(grid,i,j,0,word,"e");    //east
	                bool w= search(grid,i,j,0,word,"w");    //west
	                bool ne= search(grid,i,j,0,word,"ne");  //north-east
	                bool nw= search(grid,i,j,0,word,"nw");  //north-west
	                bool se= search(grid,i,j,0,word,"se");  //south-east
	                bool sw= search(grid,i,j,0,word,"sw");  //south-west
	                if(n||s||e||w||ne||nw||se||sw){
	                  ans.push_back({i,j});
	                }
	            }
	        }
	    }
	     return ans;
	}

};
