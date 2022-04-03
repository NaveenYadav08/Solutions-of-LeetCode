// https://leetcode.com/problems/remove-nth-node-from-end-of-list/


// make diff of n bw slow and fast
// 1 2 3 4 5 6 , n = 2    slow 1,  fast = 3
// now move till fast next is NULL
// at this point slow is behind the element I will delete 


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        for(int i=0;i<n; i++)
        {
            fast=fast->next;
        }
        
         if(!fast) return head->next;
        
        while(fast->next)
        {
            fast=fast->next;
            slow=slow->next;
        }
        
        slow->next=slow->next->next;
        return head;
    }

};
