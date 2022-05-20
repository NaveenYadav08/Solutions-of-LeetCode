// LINK 


class Solution {
public:
	ListNode* sortList(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
        // find mid
    ListNode* slow=head,*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
        
    ListNode* l2=slow->next;
    slow->next=NULL;
    ListNode* l1=head;
    l1=sortList(l1);
    l2=sortList(l2);
    ListNode* RL=mergeSort(l1,l2);
    return RL;
}
 
    
ListNode* mergeSort(ListNode *a, ListNode *b)
{
    if(a==NULL) return b;
    if(b==NULL) return a;
    
    ListNode *r;
    if(a->val < b->val)
    {
        r=a;
        r->next=mergeSort(a->next,b);
    }
    else
    {
        r=b;
        r->next=mergeSort(a,b->next);
    }
    
    return r;
}

};
