https://leetcode.com/problems/number-of-islands/


//dfs Undirected Graph ->Tree+backedges
//dfs-> runnig code visulaization (when and what to write and when to return , how backtraking works)


class Solution {
public:

	//First step:
	//dir

	vector<int>  dx = {0,0,1,-1};
	vector<int>  dy = {-1,1,0,0};//horizontally or vertically

	//Step 2:
	//isInside

	int m,n;
	bool isInside(int i,int j)
	{
		return (i>=0 && j>=0 && i<m && j< n);
	}


	void dfs(int i,int j,vector<vector<char>> & grid)
	{
		   grid[i][j]='0';//mark visited (as we don't want to visit this again)

		   for(int k=0;k<4;k++)//all possible neighbour
		   {
			  int ni=i+dx[k],nj=j+dy[k];

			  if(isInside(ni,nj) && grid[ni][nj] =='1' )//if ni and nj is inside and valid (i.e. land) 
				  dfs(ni,nj,grid);
		   }
	}


	int numIslands(vector<vector<char>>& grid) {

		//idea is in dfs from a src we are going to traverse entire connected component and mark them visited
		//so if another dfs is called it is going to be a part of some other component

		m=grid.size();n=grid[0].size();
		int count=0;

		//calling dfs
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(grid[i][j] =='1')//if valid (i.e. land) 
				dfs(i,j,grid),count=count+1;
			}
		}

		return count;
	}
};
