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


===============================================================================================================================================================
  
  FIND THE SOLUTIONS OF LINEAR DIOPHENTINE EQUATION 
  
  
// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to implement the extended
// euclid algorithm
int gcd_extend(int a, int b,
      int& x, int& y)
{
  // Base Case
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  // Recursively find the gcd
  else {
    int g = gcd_extend(b,
            a % b, x, y);
    int x1 = x, y1 = y;
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
  }
}

// Function to print the solutions of
// the given equations ax + by = c
void print_solution(int a, int b, int c)
{
  int x, y;
  if (a == 0 && b == 0) {

    // Condition for infinite solutions
    if (c == 0) {
      cout
        << "Infinite Solutions Exist"
        << endl;
    }

    // Condition for no solutions exist
    else {
      cout
        << "No Solution exists"
        << endl;
    }
  }
  
  
  int gcd = gcd_extend(a, b, x, y);

  // Condition for no solutions exist
  if (c % gcd != 0) {
    cout
      << "No Solution exists"
      << endl;
  }
  else {

    // Print the solution
    cout << "x = " << x * (c / gcd)
      << ", y = " << y * (c / gcd)
      << endl;
  }
}

// Driver Code
int main(void)
{
  int a, b, c;

  // Given coefficients
  a = 4;
  b = 18;
  c = 10;

  // Function Call
  print_solution(a, b, c);
  return 0;
}



