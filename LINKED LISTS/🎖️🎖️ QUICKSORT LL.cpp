https://practice.geeksforgeeks.org/problems/quick-sort-on-linked-list/1

class Solution {
public:

    
    void SwapValue (ListNode* a ,ListNode* b){
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
        
    }
    
    
    ListNode* Partition(ListNode* start ,ListNode* end){
        int pivotValue = start->val;
        ListNode* p = start;
        ListNode* q = start -> next;
        while(q != end){
            if (q -> val < pivotValue){
                p = p -> next;
                SwapValue(p,q);
            }
            q = q -> next;
        }
        SwapValue(p,start);
        return p;
    }
        
        
    void QuickSort(ListNode* start ,ListNode* end){
        if (start != end){
            ListNode* mid =Partition(start ,end);
            QuickSort(start,mid);
            QuickSort(mid->next,end);
        }
        
    }
        
    
    ListNode* sortList(ListNode* head) {
        QuickSort(head,NULL);
        return head;
    }
};
