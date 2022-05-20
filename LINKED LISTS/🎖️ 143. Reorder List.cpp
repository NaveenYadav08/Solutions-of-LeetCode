// link https://leetcode.com/problems/reorder-list/




class Solution {
public:
void reorderList(ListNode* head) {
        stack<ListNode *> s;
        ListNode* p = head;
        while(p){
            s.push(p);
            p = p->next;
        }
        int num_nodes = s.size();
        while(s.size() > num_nodes / 2 + 1){
            
            ListNode * temp = head->next;
            head->next = s.top();
            s.top()->next = temp;
            head = temp;
            s.pop();
        }
        s.top()->next = NULL;
    }
};
