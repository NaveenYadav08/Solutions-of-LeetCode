// LEETCODE - https://leetcode.com/problems/circular-array-loop/

// CODE 

//SLOW AND FAST POINTER 

// O(n^2)

class Solution {
public:
    
static int findNextIndex(const vector<int> &arr, bool isForward, int currentIndex) 
{
    bool direction = arr[currentIndex] >= 0;
    if (isForward != direction) {return -1;}

    int nextIndex = (currentIndex + arr[currentIndex] +arr.size() ) % arr.size();
    if (nextIndex == currentIndex) {nextIndex = -1;} // To avoid the case of 1 size cycle

    return nextIndex;
}

bool circularArrayLoop(vector<int>& arr) 
{
    for (int i = 0; i < arr.size(); i++) 
    {
        bool isForward = arr[i] >= 0;
        int slow = i, fast = i;
        do{
            slow = findNextIndex(arr, isForward, slow);  
            fast = findNextIndex(arr, isForward, fast);  
            if (fast != -1) 
            {
                fast = findNextIndex(arr, isForward, fast);  
            }
        } while (slow != -1 && fast != -1 && slow != fast);
        if (slow != -1 && slow == fast) {return true;}
    }
    return false;
}};





