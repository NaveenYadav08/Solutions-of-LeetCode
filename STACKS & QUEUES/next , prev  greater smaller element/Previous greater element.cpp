// link  https://www.geeksforgeeks.org/previous-greater-element/


// code 

void prevGreater(int arr[], int n)
{
    // Create a stack and push index of first element
    // to it
    stack<int> s;
    s.push(arr[0]);
     
    // Previous greater for first element is always -1.
    cout << "-1, ";
 
    // Traverse remaining elements
    for (int i = 1; i < n; i++) {
 
        // Pop elements from stack while stack is not empty
        // and top of stack is smaller than arr[i]. We
        // always have elements in decreasing order in a
        // stack.
        while (s.empty() == false && s.top() < arr[i])
            s.pop();
 
        // If stack becomes empty, then no element is greater
        // on left side. Else top of stack is previous
        // greater.
        s.empty() ? cout << "-1, " : cout << s.top() << ", ";
 
        s.push(arr[i]);
    }
}
