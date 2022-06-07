https://leetcode.com/problems/regions-cut-by-slashes/

https://www.youtube.com/watch?v=Wafu5vOxPRE&t=1222s











class Solution {
public:
    
vector<int> rank;  //RANK 
vector<int> parent;  //PARENT
int count;
    
int findparent(int node)
{ //initially par[x]=x;
    if(node==parent[node])
        return node;
    return parent[node]=findparent(parent[node]);
} 
    

void unionn(int u,int v)
{
    u=findparent(u);
    v=findparent(v);
    if(u!=v)
    {
    if(rank[u]<rank[v])
        parent[u]=v;
    else if(rank[u]>rank[v])
        parent[v]=u;
    
    else
    {
        parent[v]=u;
        rank[u]++;
    }
    }
    else
    {
        count++;
    }
        
}
    
int regionsBySlashes(vector<string>& grid) 
{
    int n=grid.size();
    int dots=n+1;
    
    parent=vector<int>(dots*dots+1);//resize
    rank=vector<int>(dots*dots+1);
    count=1;
    
    for(int i=0;i<parent.size();i++)//Initialize Parent and rank
    {
        parent[i]=i;
        rank[i]=1;
    }
    
    for(int i=0;i<dots;i++)//for all boundary elements having parent 0
    {
        for(int j=0;j<dots;j++)
        {
            if(i==0 or j==0 or i==dots-1 or j==dots-1)
            {
                int cellno=i*dots+j;
                if(cellno!=0)
                unionn(0,cellno);
                // BOUNDRY ko ek set me krdia 
            }
        }
    }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='/')
                {
                    int cellno1=i*dots+(j+1);
                    int cellno2=(i+1)*dots+j;
                    unionn(cellno1,cellno2);
                }
                
                else if(grid[i][j]=='\\')
                {
                    int cellno1=i*dots+j;
                    int cellno2=(i+1)*dots+(j+1);
                    
                    unionn(cellno1,cellno2);
                }
                    
            }
        }
    
    return count;
}
    
};
