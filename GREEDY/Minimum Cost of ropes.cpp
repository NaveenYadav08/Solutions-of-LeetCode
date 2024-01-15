https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long,vector<long long>,greater<long long>>pq; // creating min heap
        long long ans=0;
        for(int i=0;i<n;i++)
        pq.push(arr[i]);
        
        while(pq.size()!=1){
            long long int a=pq.top();
            pq.pop();
            long long int b=(pq.top()+a);
            pq.pop();
            ans+=b;
            pq.push(b);
            }
        return ans;
    }
};
