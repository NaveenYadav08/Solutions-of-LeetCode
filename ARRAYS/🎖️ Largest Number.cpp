// https://www.interviewbit.com/problems/largest-number/


// euailze digits and sorrt then 



static bool compareT(string a, string b) {
            return a + b > b + a;
        }

string Solution::largestNumber(const vector<int> &A) {
    
    vector<string> KA;
    for(int i=0;i<A.size();i++)
    {
        KA.push_back(to_string(A[i]));
    }
    sort(KA.begin(),KA.end(),compareT);
    
    string AA="";
    for(int i=0;i<KA.size();i++)
    {
        AA+=KA[i];
    }
    
    int flag=0;
    for(int i=0;i<AA.size();i++)
    {
        if(AA[i]!='0')
        {
            flag=1;
            break;
        }
    }
    
    if(flag==0)
    return "0";
    
    return AA;
}



