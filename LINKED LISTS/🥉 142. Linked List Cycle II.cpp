![Delete loop](https://drive.google.com/file/d/1_mEKkN5VBhoG-7fETnBtbvk3M7M_3pLC/view?usp=sharing)
               
               
               https://leetcode.com/problems/linked-list-cycle-ii/
               
 CODE 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if ((!head) || (!head->next))
            return NULL;
        
        ListNode *low, *high;
        low=head; high=head;
        
        
        while(low!=NULL and high!=NULL and high->next!=NULL)
        {
            low=low->next;
            high=high->next->next;
            if(high==low)
                break;
        }
        
        if(low==head)
            return head;
        
        else if(low==high)
        {
            low=head;
            while(low->next!=high->next)
            {
                low=low->next;
                high=high->next;
            }
            return high->next;
            
        }
        return NULL;
        
    }
};
