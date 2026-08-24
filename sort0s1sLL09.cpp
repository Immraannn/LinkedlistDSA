Node* sortZeroOne(Node* head) {
    // Dummy head for list containing 0s
    Node* zeroHead = new Node(-1);
    // Dummy head for list containing 1s
    Node* oneHead = new Node(-1);
    // Tail pointer for 0 list
    Node* zeroTail = zeroHead;
    // Tail pointer for 1 list
    Node* oneTail = oneHead;
    // Pointer to traverse original list
    Node* curr = head;
    // Traverse original linked list
    while(curr != NULL) {

        if(curr->data == 0) {              
            zeroTail->next = curr;        
            zeroTail = curr;               
        }
        else {                             
            oneTail->next = curr;          // Attach node to one list
            oneTail = curr;                // Move oneTail forward
        }

        curr = curr->next;                 // Move to next node
    }

    // Connect zero list with one list
    zeroTail->next = oneHead->next;

    // Mark end of list
    oneTail->next = NULL;

    // Update head to start of sorted list
    head = zeroHead->next;// bexause to remove dummy node(-1_

    // Delete dummy nodes to avoid memory leak
    delete zeroHead;
    delete oneHead;

    return head;                           // Return new head
}
