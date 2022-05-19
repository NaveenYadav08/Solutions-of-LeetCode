https://practice.geeksforgeeks.org/problems/implement-queue-using-linked-list/1



// insert at rear , end of LL 

// del from front , head of LL 

// 2 ptr ka track rakho 

structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; 

//Function to push an element into the queue.
void MyQueue:: push(int a)
{
    //if queue is empty, then new node is front and rear both.
    if (rear==NULL)
    {
        rear= new QueueNode(a);
        front = rear;
    }
   //adding the new node at the end of queue and changing rear.
   else
   {
        QueueNode *temp = new QueueNode(a);
        rear->next =temp;
        rear = temp;
    }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
       
    QueueNode *temp;
    temp=front;
    
    //if queue is empty, we return NULL.
    if(temp ==NULL)
        return -1;

    //if more than one node is present, we move temp one node ahead and 
    //delete front. we also update front as new temp.
    if(temp->next !=NULL)
    {
        temp=temp->next;
        int k = front->data;
        delete(front);
        front = temp;
        //returning the popped element.
        return k;
    }
    //else we delete front and make both rear and front as NULL.
    else
    {
        int k=front->data;
        delete(front);
        front=rear=NULL;
        //returning the popped element.
        return k;
    }


}
