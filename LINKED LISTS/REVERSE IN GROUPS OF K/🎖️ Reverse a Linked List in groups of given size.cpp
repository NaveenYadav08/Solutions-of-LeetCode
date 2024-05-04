// IT HAS 2 TYPES 

1 /// rev the left outs too   https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
  
  2 /// leave the left outs   https://leetcode.com/problems/reverse-nodes-in-k-group/
  
  
  
  
  TYPE 1 
  
  struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        node *curr=head;
        node *prev=NULL;
        node *next=NULL;
        int count=0;
        while(curr!=NULL and count<k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        
        if(next!=NULL)
        {
            head->next=reverse(next,k);
        }
        return prev;
    }


TYPE 2 
  
 	ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == nullptr) return head;
            cursor = cursor->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        for(int i = 0; i < k; i++){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
  
  
  
  
  


