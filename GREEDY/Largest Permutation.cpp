
// https://www.interviewbit.com/problems/largest-permutation/
// 



vector<int> Solution::solve(vector<int> &A, int B) {
    map<int,int>m;
    int n=A.size();
    for (int i=0; i<n; i++){
        m[A[i]]=i;
    }
    for (int i=0; i<n; i++){
     
        if (B==0){
            return A;
        }

        if (A[i]<n-i){
            int j=m[n-i];
            m[A[i]]=j;
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            B--;
        }
    }
    return A;
}
