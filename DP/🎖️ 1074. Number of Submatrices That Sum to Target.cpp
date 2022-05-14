// LINK  https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

// CODE 


class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
         

        int m =  matrix.size();
        int n =  matrix[0].size();


        //prefix sum for each of row 
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                matrix[i][j]+=matrix[i][j-1];
            }
        }

        int answer=0;
        
        // for each pair of coluumn find submatrix that sum upto target
        for(int start=0;start<n;start++)
        {
            for(int end=start;end<n;end++)
            {
                map<int,int> mp;

                mp[0]=1;  

                int sum=0;
 // yae sum will give me sum of submatrix  row changing and col(s,e) fix
                
                // now i am using prefix sum in vertical direction 
                

                for(int line=0;line<m;line++) // row
                {
                    
                    if(start!=0) 
                    {
                        sum+=matrix[line][end] - matrix[line][start-1];
                    }
                    else
                    {
                        sum+=matrix[line][end];
                    }
                    
                    if(mp.find(sum-target)!=mp.end())
                    {
                        answer+=mp[sum-target];
                    }
                        
                     mp[sum]++;
                }
            }

        }
        return answer;


    }
};
