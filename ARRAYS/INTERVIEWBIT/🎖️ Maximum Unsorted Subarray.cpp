Maximum Unsorted Subarray
interviewbit.com/problems/maximum-unsorted-subarray/

vector<int> Solution::subUnsort(vector<int> &A) {
int n=A.size(),l=n,r=0,mx=INT_MIN,mn=INT_MAX;
for(int i=0;i<n;i++){
    if(A[i]<mx)r=i;
    mx=max(A[i],mx);
}
for(int i=n-1;i>=0;i--){
    if(A[i]>mn)l=i;
    mn=min(mn,A[i]);
}
if(l==n)return {-1};
return {l,r};
}
