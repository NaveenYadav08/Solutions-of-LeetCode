// LINK https://www.interviewbit.com/problems/find-duplicate-in-array/
// Image is also added also see that
array is read only do it in O ( 1 ) space and O ( n ) time 

// I will use turtle , rabbbit method 

// duplicate ki wje se cycle bnegi 

// arr[0], arr[arr[0]], arr[arr[arr[0]]], arr[arr[arr[arr[0]]]] ……. 

// Each new element in the sequence is an element in arr[] at the index of the previous element.
Starting from x = arr[0], it will produce a linked list with a cycle.
The cycle appears because arr[] contains duplicate elements(at least one). The duplicate value is an entrance to the cycle.

// At some point, the tortoise enters the cycle as well, and since it’s moving slower the hare catches the tortoise up at some intersection point.
//Note that the intersection point is not the cycle entrance in the general case, but the two intersect at somewhere middle in cycle.
//Move tortoise to the starting point of sequence and hare remains within cycle and both move with the same speed i.e. tortoise = arr[tortoise] and hare = arr[hare]. 
// Now they intersect at duplicate element.


CODE 

int Solution::repeatedNumber(const vector<int> &arr) {
    
    int slow=arr[0];
    int fast=arr[0];

    do{
        slow=arr[slow];
        fast=arr[arr[fast]];
    }while(slow!=fast);

    slow=arr[0];
    while(slow!=fast)
    {
        slow=arr[slow];
        fast=arr[fast];
    }
    return slow;
}

