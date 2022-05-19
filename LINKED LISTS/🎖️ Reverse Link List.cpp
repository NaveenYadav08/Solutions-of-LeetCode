// TWO ways to do it 

// ITERATIVE   RECURSIVE 

ITERATIVE

struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node* curr, *prv, *nxt;
        curr=head;
        prv=NULL;
        nxt=NULL;
        
        while(curr!=NULL)
        { nxt=curr->next;
        curr->next=prv;
        prv=curr;
        curr=nxt;
            
        }
        return prv;
    }




RECURSIVE

struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        if(!head || !head->next) return head;
        Node* secondElement=head->next;
        head->next=nullptr;
        Node *revList=reverseList(secondElement);
        secondElement->next=head;
        return revList;
    }
