// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

// 1171. Remove Zero Sum Consecutive Nodes from Linked List

class Solution {
    public:
    ListNode* removeZeroSumSublists(ListNode* head){
        if(!head) return head; //if the linked list is empty, return head
        unordered_map<int,ListNode*> m; //make a frequency map
        ListNode* dummy = new ListNode(0); //initialise a dummy node
        dummy->next = head; //dummy will point to head.
        m[0]=dummy; //initially prefix sum is 0;
        //start traversing the Linked list;
        int prefixsum=0; //this is the running prefix sum
        while(head){ //while head is not empty
            prefixsum+=head->val; //we will keep on adding head->val to prefix sum
            if(m.find(prefixsum)!=m.end()) //find this prefix sum in map
            {
                ListNode* start = m[prefixsum]; //store the node of first occurence of the pr. sum
                int sum = prefixsum; //store this prefix sum somewhere
                while(start!=head){ //start iterating from this start node to current head
                    start=start->next; //keep on going forward
                    sum+=start->val; //keep on incrementing this sum
                    //till they are not matching delete all the pr. sum entries from map
                    if(start!=head) m.erase(sum);
                    
                }
                // this step will delete all the prefix from st+1 to head-1
                // here our subarray is m[prefix]+1 se head tk to we skip it
                m[prefixsum]->next = head->next; //finally assign the current pr sum value next
                //to our head->next this way you have pointed to right node.
            }
            else m[prefixsum]=head; //if it is not in map, then store the head corresp. to pr. sum
            head = head->next; //basic to move aage
        }
        return dummy->next;
    }
};
