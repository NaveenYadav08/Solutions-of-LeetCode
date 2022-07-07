An Integral solution is a solution such that all the unknown variables take only integer values.
Given three integers a, b, c representing a linear equation of the form : ax + by = c. 
  Determine if the equation has a solution such that x and y are both integral values.
    
    
    
Thus the algorithm to determine if an equation has integral solution is pretty straightforward. 
 

Find GCD of a and b
Check if c % GCD(a ,b) ==0
If yes then print Possible
Else print Not Possible


THIS THINK IS OBSERVED FROM EXTENDED EUCLEDIAN LEMMA

CODE
int gcd(int a, int b)
{
    return (a%b == 0)? abs(b) : gcd(b,a%b);
}
 
// This function checks if integral solutions are
// possible
bool isPossible(int a, int b, int c)
{
    return (c%gcd(a,b) == 0);
}


