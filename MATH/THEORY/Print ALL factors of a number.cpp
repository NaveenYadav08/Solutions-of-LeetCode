void printDivisors(int n)
{
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                cout <<" "<< i;
 
            else // Otherwise print both
                cout << " "<< i << " " << n/i; // as factor exist pairwise other that s like 36 = 6*6
        }
    }
}
