// link 
https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1


    void deleteNode(Node *del)
    {
        //storing the node next to given node in a pointer.	
    	Node* temp = del->next;
    	
    	//copying the data of pointer in the given current node.
    	del->data = temp->data;
    	
    	//storing the next node to pointer in link part of current node.
    	del->next = temp->next;

    	// freeing memory.
    	free(temp);
    	
    }
