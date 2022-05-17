// LINK https://www.interviewbit.com/problems/find-permutation/

?? CODE

vector<int> Solution::findPerm(const string A, int B) {
    vector<int> v;
    int s=1, l=B;

    for(int i=0 ; i <= A.size() ; i++){
        if(A[i]=='I') v.push_back(s++);
        
        else v.push_back(l--);
    }
    return v;
}
