https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1


int countRev (string s)
{
    // if length is odd, we can't balance
    if (s.length () %2) return -1;
    
    // number of opening and closing braces
    int op = 0, cl = 0;

    int res = 0; // ans
    for (int i = 0; i < s.length (); ++i)
    {
        if (s[i] == '{') op++;
        else cl++;
    
        // if cl exceeds op, then we balance the brackets till that point
        if (cl > op)
        {   cout<<i<<endl;
            res += cl - op;
            swap (cl, op);
        }
    }
    
    
    // finally, the we reverse the half of brakcets that form the unbalance
    // to balance the unbalanced pairs
    
    res += (abs (cl - op)) / 2;
    return res;
}
