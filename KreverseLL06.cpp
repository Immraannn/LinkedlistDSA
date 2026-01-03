Node* kReverse(Node* head, int k) {

    // Base case: if list is empty, nothing to reverse
    if(head == NULL) {
        return NULL;
    }

    // Step 1: Reverse first k nodes
    Node* next = NULL;   // will store next node
    Node* curr = head;   // current node (start from head)
    Node* prev = NULL;   // previous node (initially NULL)
    int count = 0;       // counter to reverse k nodes

    // Reverse k nodes or stop if list ends
    while(curr != NULL && count < k) {

        next = curr->next;   // save next node
        curr->next = prev;   // reverse the link
        prev = curr;         // move prev forward
        curr = next;         // move curr forward
        count++;             // increment count
    }

    // Step 2: Recursively reverse remaining list
    // 'next' is now pointing to (k+1)th node
    if(next != NULL) {
        head->next = kReverse(next, k);
    }

    // Step 3: prev is the new head after reversal
    return prev;
}
