// LINK https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1



struct Stack {
    int top;
    unsigned capacity;
    int* array;
};


//Function to push an integer into the stack.
void MyStack ::push(int x) 
{
    if (top == NULL) 
    {
        top = new StackNode(x);
    } 
    else 
    {
        //creating a new temp node in the stack
        StackNode *temp = new StackNode(x);
        //assigning link part of new node to top and making it top node.
        temp->next = top;
        top = temp;
    }
  
  // inserting like 
  (top) 1 - 2 - 3 -> 4
    
    insert at begin
    /// del from begin;
    
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    StackNode *temp = top;

    //if node at temp pointer is null, the stack is empty so we return -1.
    if (temp == NULL) 
    {
        return -1;
    } 
    else 
    {
        //storing the data at top node and deleting that node.
        temp = temp->next;
        int r = top->data;
        delete (top);
        top = temp;
        
        //returning the data.
        return r;
    }
}
