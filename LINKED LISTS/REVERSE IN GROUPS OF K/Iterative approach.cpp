// TYPE 1 Leave the left outs as it is
// TC - N, SC - 1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* reverseLinkedList(ListNode *head)
{
   ListNode* curr = head;  
   ListNode* prev = NULL;  
   
   while(curr != NULL){  
       ListNode* front = curr->next;  
       curr->next = prev;  
       prev = curr;  
       curr = front; 
   }
   
   return prev;  
}

ListNode* getKthNode(ListNode* curr, int k){
    // Decrement K as we already
    // start from the 1st node
    k -= 1; 
    while(curr != NULL && k > 0){
        k--; 
        curr = curr -> next; 
    }
    return curr; 
}

ListNode* reverseKGroup(ListNode* head, int k){
    // Initialize a temporary
    // node to traverse the list
    ListNode* curr = head; 

    // Initialize a pointer to track the
    // Last node of the previous group
    ListNode* prevLast = NULL; 
    

    // Get the Kth node of the current group
    while(curr != NULL){
            ListNode* kThNode = getKthNode(curr, k); 
             

              // If the Kth node is NULL
             // (not a complete group)
            if(kThNode == NULL){
                // If there was a previous group,
                // link the last node of previous group to the current node
                if(prevLast){
                    prevLast -> next = curr; 
                }break; 
            }           
            // preserve the firstnode of the next group
            ListNode* nextNode = kThNode -> next; 

            // Disconnect the Kth node
            // to prepare for reversal 
            // group size is curr to kthnode
            kThNode -> next = NULL; 
            reverseLinkedList(curr); 
            
            // First Group kthnode is our answers head
            if(curr == head){
                head = kThNode;
            }else{
                prevLast -> next = kThNode; 
            }

            prevLast = curr; // original head of the prv group
            curr = nextNode; 
    }
    
    return head; 
}
};



// TYPE 2 // 
ALSO reverse the left outs

// ONLY small changes are here and there 
// one is in the kth node function to return last node of last grp instead of nulll

// and in check cndn if kthnode==null remove thath

class Solution
{
   public:
    
    
struct node* reverseLinkedList(struct node *head)
{
   struct node* curr = head;  
   struct node* prev = NULL;  
   
   while(curr != NULL){  
       struct node* front = curr->next;  
       curr->next = prev;  
       prev = curr;  
       curr = front; 
   }
   
   return prev;  
}

struct node* getKthNode(struct node* curr, int k){
    // Decrement K as we already
    // start from the 1st node
    k -= 1; 
    node* temp=new node(0);
    while(curr != NULL && k > 0){
        k--; 
        temp=curr;
        curr = curr -> next; 
    }
    if(curr==NULL)
    return temp;
    return curr; 
}

  struct node *reverseIt (struct node *head, int k)
    {
    // Initialize a temporary
    // node to traverse the list
    struct node* curr = head; 

    // Initialize a pointer to track the
    // Last node of the previous group
    struct node* prevLast = NULL; 
    

    // Get the Kth node of the current group
    while(curr != NULL){
            struct node* kThNode = getKthNode(curr, k); 
            // preserve the firstnode of the next group
            struct node* nextNode = kThNode -> next; 

            // Disconnect the Kth node
            // to prepare for reversal 
            // group size is curr to kthnode
            kThNode -> next = NULL; 
            reverseLinkedList(curr); 
            
            // First Group kthnode is our answers head
            if(curr == head){
                head = kThNode;
            }else{
                prevLast -> next = kThNode; 
            }

            prevLast = curr; // original head of the prv group
            curr = nextNode; 
    }
    
    return head; 
    }
        


};
