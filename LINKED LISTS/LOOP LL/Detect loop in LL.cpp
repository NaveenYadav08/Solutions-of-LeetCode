https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

PROOF is must , question to easy sa hae
https://www.youtube.com/watch?v=dpqpgnTHiLs


bool detectLoop(Node* head)
    {
        // your code here
         if(!head) return false;
         
        Node* slow, *fast;
        slow=head;
        fast=head;
        while(fast and fast->next)
        {
            
            
      
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) return true;
        }
        return false;
    }
