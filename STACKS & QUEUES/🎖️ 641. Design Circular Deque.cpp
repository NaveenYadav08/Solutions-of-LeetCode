https://leetcode.com/problems/design-circular-deque/

class MyCircularDeque {
public:
    
    int *arr;
    int front;
    int rear;
    int size;
    
    
    MyCircularDeque(int k) {
        this->size=k;
        front=rear=-1; 
        arr = new int[size];
    }

    bool insertFront(int value) {
        if(isFull())return false;
        else if(front==-1){front=rear=0;}
        else{front = (front-1+size)%size;}
        arr[front]=value;
        return true; }
    
    bool insertLast(int value) {
         if(isFull())return false;
        else if(front==-1) front=rear=0;
        else rear=(rear+1)%size;
        arr[rear]=value;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())return false;
        else if(front==rear){front=rear=-1;return true;} //if there is only 1 element
        else front = (front+1)%size;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())return false;
        else if(front==rear){front=rear=-1;return true;}
        else rear = (rear-1+size)%size;
        return true;
    }
    
    int getFront() {
        if(isEmpty())return -1;
        return arr[front]; }
    
    int getRear() {
        if(isEmpty())return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        if(front==-1) return true;
        return false;
    }
    
    bool isFull() {
        if( (rear+1)%size==front ) return true;
        return false; 
    }
        
        
};
