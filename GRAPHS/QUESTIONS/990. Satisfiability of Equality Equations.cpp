//https://leetcode.com/problems/satisfiability-of-equality-equations/
// 990. Satisfiability of Equality Equations

//We first union all the variables that are equal. Then we iterate through the equations where a!=b and 
// check if a and b are in the same connected component or not. If same,return false. 

class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    
    //find operation by path compression
    int findp(int i){
        if(parent[i]!=i) parent[i]=findp(parent[i]);
        return parent[i];
    }
    
    //union operation by rank
    void union_op(int x,int y){
        int s1=findp(x);
        int s2=findp(y);

     if(s1!=s2)
     {   
          if(rank[s1]<rank[s2])
         {parent[s1]=s2;
         rank[s2]+=  rank[s1];
         }
        else
         {parent[s2]=s1;
         rank[s1]+=rank[s2];
         
         }

     }
    }

    
    
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<parent.size();i++) parent[i]=i;
        
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='='){
             int a=equations[i][0]-'a';
            int b=equations[i][3]-'a';
                union_op(a,b);
            }
        }
        
        
        for(int i=0;i<equations.size();i++){
            int a=equations[i][0]-'a';
            int b=equations[i][3]-'a';
            if(equations[i][1]=='!' && findp(a)==findp(b)) return false;
        }
         return true;   
        }
    
};
