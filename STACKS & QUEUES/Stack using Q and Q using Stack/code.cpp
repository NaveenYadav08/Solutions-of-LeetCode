
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
    
            for(int i=0;i<q1.size()-1;i++)
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
  
  
