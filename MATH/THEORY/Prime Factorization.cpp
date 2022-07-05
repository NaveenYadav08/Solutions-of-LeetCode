https://practice.geeksforgeeks.org/problems/prime-factors5052/1/

class Solution{
	public:
	
vector<int> soe(int n)
{

    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    vector<int> ANS;
    for (int p = 2; p * p <= n; p++)
    {

        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 

    for (int p = 2; p <= n; p++)
        if (prime[p])
            ANS.push_back(p);
            
            return ANS;
}	

vector<int>AllPrimeFactors(int N) {
	    // Code here
	    vector<int> ans=soe(N);
	    vector<int> ANS;
	    for(int i=0; i<ans.size() and N>0; i++){
	         if(N%ans[i]==0)
	           ANS.push_back(ans[i]);
	         while(N%ans[i]==0){
	             N=N/ans[i];
	         }
	    }
	    if(N>1)
	      ANS.push_back(N);
	    return ANS;
	}
};
