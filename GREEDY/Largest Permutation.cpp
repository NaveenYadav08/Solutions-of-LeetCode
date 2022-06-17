
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

        if (A[i]<n-i){  // 1 < 4  curr , what curr should be
            int j=m[n-i]; // wo no jo idhar hae wo kaha pr hae 
            m[A[i]]=j; // swap them
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            B--;
        }
    }
    return A;
}
