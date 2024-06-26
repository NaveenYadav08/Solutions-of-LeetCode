https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1

CODE 1  SC = TC = N

long swapCount(string s)
{
    // Keep track of '['
    vector<int> pos; // first store the pst of all opening bracket
    for (int i = 0; i < s.length(); ++i)
        if (s[i] == '[')
            pos.push_back(i);
  
  
 
    int count = 0; // To count number of encountered '['
    int p = 0;  // To track position of next '[' in pos
    long sum = 0; // To store result
 
    for (int i = 0; i < s.length(); ++i)
    {
        // Increment count and move p to next position
        if (s[i] == '[')
        {
            ++count;
            ++p;
        }
        else if (s[i] == ']')
            --count;
 
        // We have encountered an unbalanced part of string
        if (count < 0)
        {
            // Increment sum by number of swaps required
            // i.e. position of next '[' - current position
            sum += pos[p] - i;
            swap(s[i], s[pos[p]]);
            ++p;
 
            // Reset count to 1
            count = 1;
        }
    }
    return sum;
}













CODE 2 SC = 1
  
  TC = N
  
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        int swap=0, imbalance=0;
    	int countLeft=0, countRight=0;
    	int sizeOfArray=S.size();
    
    	for(int i=0;i<sizeOfArray;++i){
    
    		if(S[i] == '[')  
            { 
                    // increment count of Left bracket 
                    countLeft++;  
                    if(imbalance > 0)  
                    { 
                        // swaps count is last swap count + total  
                        // number imbalanced brackets 
                        swap += imbalance;  
                        // imbalance decremented by 1 as it solved 
                        // only one imbalance of Left and Right 
                        imbalance--;      
                    } 
            } 
            else if(S[i] == ']' )  
            { 
                    // increment count of Right bracket 
                    countRight++;  
                    // imbalance is reset to current difference  
                    // between Left and Right brackets 
                    imbalance = (countRight-countLeft);  
            } 
    	}
    
    	return swap;
        
    }
};
