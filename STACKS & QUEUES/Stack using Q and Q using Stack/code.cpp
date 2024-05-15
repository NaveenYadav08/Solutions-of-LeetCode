
STACK USIING QUEUE  - 1 q     2 Q solution 
https://leetcode.com/problems/implement-stack-using-queues/


//using single queue
class MyStack {
        queue<int>q1;
 public:
    MyStack() {

    }
    
    void push(int x) {
            q1.push(x);
    
            int t = q1.size();
            for(int i=0;i<t-1;i++)
            {
                q1.push(q1.front());
                q1.pop();
            }     
    }
    
    int pop() {
             int p=q1.front();
            q1.pop();
            return p;        
    }
    
    int top() {
       return q1.front(); 
    }
    
    bool empty() {
        return q1.empty();
    }
};


//using two queues
// top = front 


class MyStack {
        queue<int>q1;
        queue<int>q2;   
public:
    MyStack() {

    }
    
    void push(int x) {
            q2.push(x);
    
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }

            swap(q1,q2);        
    }
    
    int pop() {
             int p=q1.front();
            q1.pop();
            return p;        
    }
    
    int top() {
       return q1.front(); 
    }
    
    bool empty() {
        return q1.empty();
    }
};






--------------------------------------------------------------------------------------
  
  
// https://leetcode.com/problems/implement-queue-using-stacks/

// one stack recursion

class MyQueue {
    stack<int> s1;
    
    public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(empty()){
            s1.push(x);
            return ;
        }
        int top = pop();
        push(x);
        s1.push(top);
       
    }
    
    int pop() {
        int top = s1.top();
        s1.pop();
        return top;
    }
    
    int peek() {
         int top = s1.top();
        return top;
    }
    
    bool empty() {
        return s1.size()==0;
    }
};



// two stack  

class MyQueue {
    stack<int> s1,s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        //Move all elements from s1 to s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        //push item into s1
        s1.push(x);
        //push everything back to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        
    }
    
    int pop() {
        if(s1.empty()){
            return -1;
        }
        int top=peek();
        s1.pop();
        return top;
    }
    
    int peek() {
        int t=s1.top();
        return t;
    }
    
    bool empty() {
        if(s1.empty())
            return true;
        return false;
    }
};
        
