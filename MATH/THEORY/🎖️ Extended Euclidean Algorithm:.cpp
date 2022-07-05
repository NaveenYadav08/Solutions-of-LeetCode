Extended Euclidean Algorithm: 
Extended Euclidean algorithm also finds integer coefficients x and y such that: 

  ax + by = gcd(a, b)   { a , b given find x,y }
    
    Time Complexity : O(logn)
      
 code
 
 
 // Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int &x, int &y)
{
	// Base Case
	if (a == 0)
	{
		x = 0;
		y = 1;
		return b;
	}

	int x1, y1; // To store results of recursive call
	int gcd = gcdExtended(b%a, a, x1, y1);

	// Update x and y using results of
	// recursive call
	x = y1 - (b/a) * x1;
	y = x1;

	return gcd;
}

// Driver Code
int main()
{
	int x=0, y=0, a = 30, b = 20;
	int g = gcdExtended(a, b, x, y);
	cout << "GCD(" << a << ", " << b
		<< ") = " << g << endl;
  cout<<x<<"  "<<y<<endl;
	return 0;
}
