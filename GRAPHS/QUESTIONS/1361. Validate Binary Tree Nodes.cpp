https://leetcode.com/problems/validate-binary-tree-nodes/






Observation

A tree has a single root node (in-degree = 0) and all other nodes have in-degree = 1. We can use this observation to find the root. We can then traverse the tree using that root to check if all nodes have been visited exactly once.

Complexity

Space: O(n).
Time: O(n).






class Solution {
public:
    
    // DFS from root to validate that all nodes are visited.
   int countNodes(vector<int> &l,vector<int> &r,int root)   
    {
        if(root==-1)
            return 0;
        return 1+countNodes(l,r,l[root])+countNodes(l,r,r[root]);
    }
    
    
    
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        vector<int> inDegree(n,0);
        int root=-1;
        
    for(int i=0;i<leftChild.size();i++)
    {if(leftChild[i]!=-1&&inDegree[leftChild[i]]++==1)  //If in-degree exceeds 1 return false.
                return false;
    else if(rightChild[i]!=-1&&inDegree[rightChild[i]]++==1)  //If in-degree exceeds 1 return false.
                return false;}
        
        
        for(int i=0;i<leftChild.size();i++)    //Find root and also check for multiple roots.
        {if(inDegree[i]==0)  //If in-degree = 0 and has children it's a root.
                if(root==-1)   //Store the root.
                    root=i;
                else    //We have multiple roots, return false
                    return false;}
        
        if(root==-1)
            return false;
        
        
        return countNodes(leftChild,rightChild,root)==n;
    }
};
