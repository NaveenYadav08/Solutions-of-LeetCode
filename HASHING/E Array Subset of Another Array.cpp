// GFG - https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1

// code 
string isSubset(int a1[], int a2[], int n, int m) {
    
    if(n<m)
    return "No";
    
    unordered_map<int,int> A2;
    for(int x=0;x<m;x++)
    {
        A2[a2[x]]++;
    }
    
    for(int x=0;x<n;x++)
    {
        if(A2.find(a1[x])!=A2.end())
        {
            A2[a1[x]]--;
        }
    }
    
    int flag=0;
    for(auto x:A2)
    {
        if(x.second!=0)
        {
            flag=1;
            break;
        }
    }
    
    if(flag==1)
    return "No";
    
    return "Yes";
}
