https://leetcode.com/problems/rotate-list/

// code 
class Solution {
public:
   ListNode* rotateRight(ListNode* head, int k) {
        // edge cases 
        if (!head || !head->next || k == 0) return head;
        
        // compute the length
        ListNode *cur = head;
        int len = 1;
        while (cur->next && ++len) 
            cur = cur->next;
        
        // go till that node, circle bna dia
        cur->next = head;
        k = k % len; 
        k = len - k;
        while (k--) cur = cur->next;
        cout<<cur->val<<endl;
        
        
        // make the node head and break connection 
        head = cur->next;
        cur->next = NULL;
        
        
        return head; 
    }
};
