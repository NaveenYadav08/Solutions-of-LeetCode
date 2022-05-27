https://practice.geeksforgeeks.org/problems/rotate-bits4524/1


class Solution
{
  public:
        vector <int> rotate (int n, int d)
    {
        // rotation of 16 is same as rotation of 0
        // rotation of 17 is same as rotation of 1
        // and so on.
        d = d % 16;
        vector <int> res (2);
        
        // storing n in a temporary variable
        int temp = n;
        
        int mask = (1 << d) - 1; // picking up the leftmost d bits
        int shift = (temp & mask); 
        temp = (temp >> d); // moving the remaining bits to their new location
        temp += (shift << (16 - d)); // adding removed bits at rightmost end
        res[1] = temp; // storing the new number
    
    
        temp = n;
        mask = ~((1 << (16 - d)) - 1); // picking the rightmost d bits
        shift = (temp & mask);
        temp = (temp << d); // moving the remaining bits to their new location
        temp += (shift >> (16 - d)); // adding removed bits at leftmost end
        res[0] = temp; // storing the new number
    
        mask = (1 << 16) - 1;
		res[0] = (res[0] & mask);
		
        return res;
    }
    // Contributed By: Pranay Bansal

};
