// gfg https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1#

// code 1 

//lexiographically sorted no need to sort at end dont pass it by refrence 
//sort it initailly and pass by value 
class Solution
{
	public:
	void helper(string S, vector<string>& ans, int i, int n)
	{
	    if(i==n)
	    {
	        ans.push_back(S);
	        return;
	    }
	    if(i>n)
	    return;
	    for(int k=i;k<n;k++)
	    {
	        swap(S[i],S[k]);
	        helper(S,ans,i+1,n);
	    }
	}
		vector<string>find_permutation(string S)
		{
		    sort(S.begin(),S.end());
		    vector<string> ans;
		    helper(S,ans,0,S.size());
		    return ans;
		}
};

//IS CODE KA OUTPUT 
ABC  swapped A with A 0 0 ABC
ABC  swapped B with B 1 1 ABC
ABC  swapped C with C 2 2 ABC
ABC
ABC  swapped B with C 1 2 ACB
ACB  swapped B with B 2 2 ACB
ACB
ABC  swapped A with B 0 1 BAC
BAC  swapped A with A 1 1 BAC
BAC  swapped C with C 2 2 BAC
BAC
BAC  swapped A with C 1 2 BCA
BCA  swapped A with A 2 2 BCA
BCA
BAC  swapped B with C 0 2 CAB
CAB  swapped A with A 1 1 CAB
CAB  swapped B with B 2 2 CAB
CAB
CAB  swapped A with B 1 2 CBA
CBA  swapped A with A 2 2 CBA
CBA


or working 


// code 2 
// pass by refrence or value and backtracking and need to sort at end 
// iska tree to same gfg ke tree jesa hae
// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

class Solution
{
	public:
	void helper(string &S, vector<string>& ans, int i, int n)
	{
	    if(i==n)
	    {
	        ans.push_back(S);
	        return;
	    }
	    if(i>n)
	    return;
	    for(int k=i;k<n;k++)
	    {
	        swap(S[i],S[k]);
	        helper(S,ans,i+1,n);
	        swap(S[i],S[k]); //backtrack
	    }
	}
		
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    helper(S,ans,0,S.size());
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



// CODE 3 
// 	STL
// next permutation 

class Solution
{
    public:
        vector<string>find_permutation(string S)
        {
            vector<string>res;
            // sort the string in lexicographically order
            sort(S.begin(), S.end());
            do
            {
                // keep adding while there is next permutation
                res.push_back(S);
            }while(next_permutation(S.begin(), S.end()));
            return res;
        }
};
