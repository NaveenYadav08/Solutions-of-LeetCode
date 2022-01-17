https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1#

BASICALLY DFS - "check if current cell is Valid or not  if Valid go to its adjacents"

  
  
CODE - 
  
class Solution {
public:

bool isValid(int sr, int sc, vector<vector<int>>& image)
{
    if(sr>=image.size() || sr<0 || sc>=image[0].size() || sc<0 )
    return false;
  
    return true;
}

void helper(vector<vector<int>>& image, int sr, int sc, int newColor, int clr)
{
    if(isValid(sr,sc, image) and image[sr][sc]==clr)
    {  
        image[sr][sc]=newColor;
        helper(image,sr+1,sc,newColor, clr);
        helper(image,sr-1,sc,newColor, clr);
        helper(image,sr,sc+1,newColor, clr);
        helper(image,sr,sc-1,newColor, clr);
        
    }
    
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
     {
        // Code here
        int clr=image[sr][sc];
        if(clr!=newColor)
        helper(image, sr, sc, newColor, clr);
        
        return image;
    }
};
