https://www.youtube.com/watch?v=46zD5d9y9b4

Relationship bw problem and subproblem 
K not going to change but n will change

class Solution
{
    public:
int helper(int n, int k)
{
    if(n==1)
    return 1;
    
    return (helper(n-1,k)+(k-1))%n + 1 ;
}

int josephus(int n, int k)
{
   //Your code here
   return helper(n,k);
   
}
};
