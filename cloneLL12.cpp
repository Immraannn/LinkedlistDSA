Node* cloneList(Node* head) {

    // Case 1: Empty list
    if(head == NULL)
        return NULL;

    // Create first node of cloned list
    Node* cloneHead = new Node(head->data);

    // Pointers to traverse original and cloned lists
    Node* original = head->next;
    Node* clone = cloneHead;

    // Traverse original list
    while(original != NULL) {

        // Create a new node with same data
        clone->next = new Node(original->data);

        // Move clone pointer forward
        clone = clone->next;

        // Move original pointer forward
        original = original->next;
    }

    // Return head of cloned list
    return cloneHead;
}
