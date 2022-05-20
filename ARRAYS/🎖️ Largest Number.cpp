// https://www.interviewbit.com/problems/largest-number/

// 



// euailze digits and sorrt then if same like 3 , 30 put 3 before

bool compareT(int A,int B)
{
    int dA= floor(log10(A)+1);
    int dB=floor(log10(B)+1);
    
    int cA=A;
    int cB=B;
    
    if(dA<dB)
    {
        int diff=dB-dA;
        cA=cA*(pow(10,diff));
    }
    else if(dA>dB)
    {
        int diff=dA-dB;
        cB=cB*(pow(10,diff));  
        
    }

    // EQUALIZE DIGITS
    
    if(cA>cB)
    return true;
    
    else if(cA==cB)
    {
        if(A<B)
        return true;
    }
    
    return false;
}

string Solution::largestNumber(const vector<int> &A) {
    
    vector<int> KA=A;
    sort(KA.begin(),KA.end(),compareT);
    
    string AA="";
    for(int i=0;i<A.size();i++)
    {
        AA+=to_string(KA[i]);
    }
    if(stoi(AA)==0)
    {
        return "0";
    }
    return AA;
}
