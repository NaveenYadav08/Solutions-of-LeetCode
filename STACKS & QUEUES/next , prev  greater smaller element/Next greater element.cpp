https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1/
Next Greater Element 


// iterate back 
// while(not empty and top <= srr[i]) pop 

// if(empty) ans[i]=-1;
// else ANS[i]=stack top()
//push (srr[i]) // each time;

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long > s;
        vector<long long > res (n);
        
        //traversing the array from last element in backward direction.
        for (int i = n-1; i >= 0; i--)
        {
            //while element at top of stack is less than or equal to
            //current array element, we pop elements from the stack.
            while (!s.empty () and s.top () <= arr[i])
                s.pop ();
            
            //if stack becomes empty, we store -1 in the answer list 
            //else we store the top element of the stack.   
            if (s.empty ())
                res[i] = -1;
            else 
                res[i] = s.top ();
            
            //pushing the current array element into the stack.  
            s.push (arr[i]);
        }
        //returning the list.
        return res;
    }
};
