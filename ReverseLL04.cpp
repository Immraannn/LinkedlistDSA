//ITERATIVE METHOD
Node* reverseLinkedList(Node* head) {
    Node* prev = NULL;      // previous node
    Node* curr = head;      // current node
    Node* next = NULL;      // next node

    while (curr != NULL) {
        next = curr->next;  // store next
        curr->next = prev;  // reverse link
        prev = curr;        // move prev forward
        curr = next;        // move curr forward
    }

    return prev;            // new head
}


// RECURSUVE METHOD
Node* reverseRec(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* newHead = reverseRec(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

