https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1



class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        // https://youtu.be/ju8vrEAsa3Q
        // WATCH THIS
        
        if(n==1)
        return k;
        
        int MOD=1000000007;
        
        long long same=k; // ways of last 2 same clr
        long long diff=k*(k-1); // ways last 2 not same // upto k =2 
        long long total=same+diff;
        
        for(int i=3;i<=n;i++)
        {
            same=diff; // pichli bar ke diff ka clr use krlu to  ok 
            diff=total*(k-1);  // diff ke liae pichle total lelo and unke end wale clr 
            // se diff clr add krdo
            total= ( (same%MOD) + (diff%MOD) )%MOD ;
        }
        
        return total;
    }
};
