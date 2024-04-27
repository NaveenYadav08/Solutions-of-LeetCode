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
    
int count=0;
ListNode* temp=head;
    
while(temp!=NULL)
{
count++;
temp=temp->next;
}

    ListNode* curr=head;
    ListNode* prev=NULL;
    ListNode* next;int cnt=0;
    while(curr!=NULL && cnt<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        cnt++;
    }
    
    if(next!=NULL && (count-k)>=k)
    {
        head->next=reverseKGroup(curr,k);
    }
    else
    {
        head->next=curr;
    }
    return prev;
}
  
  
  
  
  


