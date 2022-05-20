// link  https://leetcode.com/problems/design-linked-list/
// 

class Node {
public:
    int val;
    Node* next = NULL;

    Node(int val) {
        this->val = val;
    }
};
class MyLinkedList {
    Node* head;
public:
    MyLinkedList() {
        head = NULL;
    }

    int get(int index) {
        if(index < 0)   return -1;                  // Invalid -ve index

        Node* curr = head;
        while(index--  &&  curr)                    // Search for 'index' node
            curr = curr->next;

        if(curr == NULL)                            // Index is greater than nodes available
            return -1;

        return curr->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);

        newNode->next = head;                       // Put 'newNode' before previous head node
        head = newNode;                             // And make 'newNode' as 'head'
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if(!head) {                                 // This is first node to be inserted, thus becomes 'head'
            head = newNode;
            return;
        }

        Node* curr = head;
        while(curr->next)                           // Reach last node
            curr = curr->next;

        curr->next = newNode;                       // Append 'newNode' to last of list
    }

    void addAtIndex(int index, int val) {
        if(index < 0)                               // Invalid -ve index
            return;

        Node *newNode = new Node(val);

        Node *dummy   = new Node(0);                // Add 'dummy' at start for ease
        dummy->next = head;

        Node *curr = dummy;

        while(curr  &&  index--)                    // Reach 1-node before 'index' node
            curr = curr->next;

        if(curr == NULL)                            // List size is less than required index
            return;

        newNode->next = curr->next;                 // Insert node after 'curr'
        curr->next = newNode;

        head = dummy->next;                         // Re-assign 'head' if needed

        delete dummy;
    }

    void deleteAtIndex(int index) {
        if(index < 0)                               // Invalid -ve index
            return;

        Node *dummy   = new Node(0);                // Add 'dummy' at start for ease
        dummy->next = head;

        Node *curr = dummy;

        while(curr  &&  index--)                    // Reach 1-node before 'index' node
            curr = curr->next;

        if(!curr  ||  !curr->next)                  // List size is less than required index
            return;                                 // or the node at given index is 'NULL'

        Node* del = curr->next;

        curr->next = curr->next->next;              // Remove pointer, pointing to 'index' node, and
        delete del;                                 // then remove it from list and memory

        head = dummy->next;                         // Re-assign 'head' if needed

        delete dummy;
    }
};
