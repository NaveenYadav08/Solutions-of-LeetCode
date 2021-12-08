// GFG https://practice.geeksforgeeks.org/problems/relative-sorting4323/1

// CODE 

class Solution{
    public:
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        map<int,int>mp;
        
        //storing all the elements of first array in map.
        for(int i=0;i<N;i++)
        {
            mp[A1[i]]++;
        }
        int j=0;
        for(int i=0;i<M;i++)
        {
            //if any element of second array has value more than 0 in map, we
            //store those elements in array and decrement the count in map.
            while(mp[A2[i]]>0)
            {
                A1[j++]=A2[i];
                mp[A2[i]]--;
            }
        }
        
        //iterating over the map which helps in storing
        //elements in increasing order.
        for(auto it:mp)
        {  
        
            //we store the elements if their frequency is more than 0.
            if(it.second>0)
            {  cout<<it.first<<" "<<endl;
                //storing elements as many times as their count in output array.
                while(it.second>0)
                {
                    A1[j++]=it.first;
                    it.second--;
                }
            }
        }
        //returning the output.
        return A1;
    } 
};
