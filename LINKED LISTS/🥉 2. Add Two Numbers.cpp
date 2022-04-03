https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
    

    
    ListNode* addTwoNumbers(ListNode* first, ListNode* second) {
        ListNode *sum=NULL;
        int carry=0;
        
        //using a loop till both lists and carry gets exhausted.
        while( first!=NULL || second!=NULL || carry!=0 )
        {
            //using a variable to store sum of two digits along with carry.
            int newVal = carry;
            
            //if ListNodes are left in any list, we add their val in newVal.
            if(first) newVal += first->val;
            if(second) newVal += second->val;
        
            //updating carry.
            carry = newVal/10;
            
            //using modulus to store only a single digit at that place.
            newVal = newVal%10;             
            
            //creating new ListNode which gets connected with other ListNodes that 
            //we get after calculating sum of respective digits.
            ListNode* newListNode = new ListNode(newVal);
            
            //storing the previously made ListNodes in the link part of new ListNode.
            newListNode->next = sum;
            
            //making the new ListNode as the first ListNode of all previously made ListNode.
            sum = newListNode;
            
            //moving ahead in both lists.
            if(first) first = first->next; 
            if(second) second = second->next;
        }
        return reverse(sum);
    }
};
