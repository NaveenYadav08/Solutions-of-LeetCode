// https://www.interviewbit.com/problems/first-missing-integer/

int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    // first making all negative and 0 elements set to 1e9
    for(int i = 0; i<n; i++)
    {
        if(A[i] <= 0)
        A[i] = 1e9;
    }

    // then using the negativ marking technique in the array
    for(int i = 0; i<n; i++)
    {
        int go = abs(A[i])-1;
        if(go < n && A[go] > 0)
        A[go] = -A[go];
    }
    // is the element is not negative that means it is not present in the array.
    for(int i = 1; i<=n; i++)
    {
        if(A[i-1] > 0)
        return i;
    }
    // if all are negative marked that means n+1 element will be our answer.
    return n+1;
}
