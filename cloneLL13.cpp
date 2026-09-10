Node* cloneList(Node* head) {
    if(head == NULL)
        return NULL;
    Node* cloneHead = new Node(head->data);
    Node* original = head->next;
    Node* clone = cloneHead;
    while(original != NULL) {
        clone->next = new Node(original->data);
        clone = clone->next;
        original = original->next;
    }
    return cloneHead;
}
