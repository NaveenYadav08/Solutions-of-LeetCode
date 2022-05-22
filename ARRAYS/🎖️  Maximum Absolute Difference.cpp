https://www.interviewbit.com/problems/maximum-absolute-difference/




int Solution::maxArr(vector<int> &A) {
    int max1,max2,min1,min2;
    max1=max2=INT_MIN;
    min1=min2=INT_MAX;
    int n=A.size();
    
    for(int i=0;i<n;i++)
    {
        max1=max(max1, A[i]+i);
        max2=max(max2,A[i]-i);
        min1=min(min1, A[i]+i);
        min2=min(min2,A[i]-i);
    }
    
    int ans=max(abs(max1-min1),abs(max2-min2));
    return ans;
}
