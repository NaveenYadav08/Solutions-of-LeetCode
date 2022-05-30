https://www.interviewbit.com/problems/n3-repeat-number/


int Solution::repeatedNumber(const vector<int> &A) {
    
    int n=A.size();
    int num1=-1;
    int num2=-1;
    int cnt1=0;
    int cnt2=0;
    
    for(int i=0;i<n;i++)
    {   
        if(A[i]==num1)
        {
            cnt1++;
        }
        else if(A[i]==num2)
        {
            cnt2++;
        }
        else if(num1==-1)
        {
            num1=A[i];
            cnt1=1;
        }
        else if(cnt1==0)
        {
            cnt1++;
        }
        else if(num2==-1)
        {
            num2=A[i];
            cnt2=1;
        }
        else if(cnt2==0)
        {
            cnt2++;
        }
        
    }
    
    return -1;
    
    
}
