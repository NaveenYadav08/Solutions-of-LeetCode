// LINK   https://www.interviewbit.com/problems/insertion-sort-list/

// CODE 

ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode* dummy = new ListNode(0);
     // dummy 
    ListNode* curr = A;
   // curr ptr
    ListNode* pre = dummy;
 // prev = dummy ( to keep track in our sorted list )
    ListNode* next = NULL;
        // for next pointer 

    while(curr){
        next = curr->next;
        while(pre->next && pre->next->val<curr->val){
            pre = pre->next;
        }
 // prev list is sorted 
        //jbtk prev mae aesi value na mile jo large he curr ki val sae 

        curr->next = pre->next; // curr next = prv next  eg dumm  1  3 NULL
                                // 2 NULL

                                // in it after the loop prv point to 1
                                // 2 ->3_>null
                                // 
        pre->next = curr; // 1 - > 2 ->3 -> NULL

        pre = dummy; // always point back to start of sorted list 
        curr = next; 
    } 
    return dummy->next;


 
 }
