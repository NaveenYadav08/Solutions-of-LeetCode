/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */




https://leetcode.com/problems/odd-even-linked-list/




class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
            return head;
        
        ListNode *O,*E, *OO, *EE;
        O=head;
        
        if(head->next)
        E=head->next;
        else
        E=NULL;
        
        OO=O;
        EE=E;
        
        while(OO and EE and EE->next and OO->next)
        {
            
            if( OO->next==NULL or OO->next->next==NULL)
                OO->next=NULL;
            else
            {OO->next=OO->next->next; OO=OO->next;}
            
            if( EE->next==NULL or EE->next->next==NULL)
                EE->next=NULL;
            else
            {EE->next=EE->next->next;  EE=EE->next;}
            
        }
        
        OO->next=E;
        return O;
        
        
        
    }
};
