question - 
https://leetcode.com/problems/copy-list-with-random-pointer/





https://drive.google.com/file/d/1RUyQclEzbmgp3rUpu7BVoMnS3YgV6k99/view?usp=sharing      ( PIC  - 1 )
https://drive.google.com/file/d/1bLdGpw0rg7G5Mht40LeLHBog9x-0VXxY/view?usp=sharing      ( PIC - 2 ) 

first add same node to next of nodes 
then make random pointer of those adjacent nodes
then separate them 













code 

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr=head;
        Node* temp;
        
        if(head==NULL) return head;
        
        while(curr)
        {
            temp=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=temp;
            curr=temp;
        }
        curr=head;
        while(curr)
        {
            curr->next->random=curr->random?curr->random->next:curr->random;
            curr=curr->next->next;
        }
        
        Node* original = head;
        Node* copy =head->next;
        temp=copy;
        while(original and copy)
        {
            original->next=original->next->next;
            copy->next=copy->next?copy->next->next:copy->next;
            original = original->next;
            copy=copy->next;
        }
        return temp;
    }
};
