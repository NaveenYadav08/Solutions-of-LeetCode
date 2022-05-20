// linkl https://leetcode.com/problems/copy-list-with-random-pointer/


// https://leetcode.com/problems/copy-list-with-random-pointer/

// 138. Copy List with Random Pointer


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
