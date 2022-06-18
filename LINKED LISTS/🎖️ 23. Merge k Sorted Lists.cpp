// https://leetcode.com/problems/merge-k-sorted-lists/
/// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

class Solution {
public:
    
    ListNode* merge(ListNode *a, ListNode *b)
{
    if(a==NULL) return b;
    if(b==NULL) return a;
    
    ListNode *r;
    if(a->val < b->val)
    {
        r=a;
        r->next=merge(a->next,b);
    }
    else
    {
        r=b;
        r->next=merge(a,b->next);
    }
    
    return r;
}
    
int n; 
vector<ListNode*> LIST;

ListNode* ans(int i)
{    
    if(i+1==n) return LIST[i];
   
   return merge(LIST[i], ans(i+1));
}


ListNode *mergeKLists(vector<ListNode*>& lists)
{
   // Your code here
   
     n = lists.size();
    
    for(int i=0;i<n;i++)
    {
        if(lists[i]!=NULL)
            LIST.push_back(lists[i]);
    }
     n=LIST.size();
    if(n==0)
        return NULL;
     return ans(0);
    
}

};

