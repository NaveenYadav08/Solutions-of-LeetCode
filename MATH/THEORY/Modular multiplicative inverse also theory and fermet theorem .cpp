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
  
  
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  
  Method 3 FERMET'S LITTLE THEOREM 
  (Works when m is prime) 
  and a ia positive integer  and is not divisible by m
If we know m is prime, then we can also use Fermats’s little theorem to find the inverse. 
  
  so basically if m dont divide a 

a^(m-1) ≅ 1 (mod m)
If we multiply both sides with a-1, we get 

a^(-1) ≅ a^ (m-2) (mod m)
  
  
  Time Complexity: O(log m)
    
    
   
    
    CODE 
// To find GCD of a and b
int gcd(int a, int b);
 
// To compute x raised to power y under modulo m
int power(int x, unsigned int y, unsigned int m);
 
// Function to find modular inverse of a under modulo m
// Assumption: m is prime
void modInverse(int a, int m)
{
    int g = gcd(a, m);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // If a and m are relatively prime, then modulo
        // inverse is a^(m-2) mode m
        cout << "Modular multiplicative inverse is "
             << power(a, m - 2, m);
    }
}
 
// To compute x^y under modulo m
int power(int a, unsigned int b, unsigned int m)
{
    if(b == 0) return 1;
    a = a % m;
    int temp = power(a, b/2, m);
    if(b&1)
        return (((temp * temp) % m) * a) % m;
    else
        return (temp * temp) % m;
}


 
// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
// Driver code
int main()
{
    int a = 3, m = 11;
 
    // Function call
    modInverse(a, m);
    return 0;
}
    
    
 
