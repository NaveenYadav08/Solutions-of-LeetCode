// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

// 430. Flatten a Multilevel Doubly Linked List

// WATCH THIS 

// https://youtu.be/F-oPHhK1em0


class Solution {
public:
    Node* flatten(Node* head) {
         Node* cur = head;
         Node* tail = head;
        stack<Node*> stack;
         while(cur != NULL) {
            if(cur->child != NULL) {
                Node* child = cur->child;
                if(cur->next != NULL){ 
                    stack.push(cur->next);
                    cur->next->prev = NULL; 
                }
                cur->next = child;
                child->prev = cur;
                cur->child = NULL;
            }
            tail = cur;
            cur = cur->next;
            
    }
        
        while(!stack.empty()) {
            cur = stack.top();
            stack.pop();
            tail->next = cur;
            cur->prev = tail;
            while(cur != NULL) {
                tail = cur;
                cur = cur->next;
            }
        }
        return head; }
};
