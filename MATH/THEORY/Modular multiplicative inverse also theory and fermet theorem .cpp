Given two integers ‘a’ and ‘m‘, find modular multiplicative inverse of ‘a’ under modulo ‘m’.
  it means that find  b so that ( a * b ) % m = 1
  
The multiplicative inverse of “a modulo m” exists if and only if a and m are relatively prime (i.e., if gcd(a, m) = 1).
  
  see it in proofs 
  
  
  
  IT CAN BE SOLVED BY 2 WAYS FERMAT THEOREM and EXTENDED EUCLEDIAN ALGO
  
  //////////////////////////////////////////////////////////////////////////////
  CODE   EXTENDED EUCLEDIAN LEMMA 
  
// C++ program to find multiplicative modulo
// inverse using Extended Euclid algorithm.


// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int* x, int* y);

// Function to find modulo inverse of a
void modInverse(int a, int m)
{
  int x, y;
  int g = gcdExtended(a, m, &x, &y);
  if (g != 1)
    cout << "Inverse doesn't exist";
  else
  {
    
    // m is added to handle negative x
    int res = (x % m + m) % m;
    cout << "Modular multiplicative inverse is " << res;
  }
}

// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int& x, int& y)
{
  
  // Base Case
  if (a == 0)
  {
    x = 0, y = 1;
    return b;
  }
  
  // To store results of recursive call
  int x1, y1;
  int gcd = gcdExtended(b % a, a, x1, y1);

  // Update x and y using results of recursive
  // call
  x = y1 - (b / a) * x1;
  y = x1;

  return gcd;
}


Time Complexity: O(log m)
