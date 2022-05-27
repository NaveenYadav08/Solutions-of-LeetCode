// link   https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

// code 

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        if(n==0)return 0;
       
        int x = log2(n);
       
       // x is nearest power of 2
       // pow(2,x-1)*x  yae   us neraest power tk kae sare set bit krlega count
       
       // n - pow(2,x) + 1 yae from nerarst power to n tk kae msb kae e1 krlega count  
        return ((pow(2,x-1)*x)+(n-pow(2,x)+1) + countSetBits(n-pow(2,x)));
    }
};
