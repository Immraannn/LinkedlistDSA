//ITERATIVE METHOD
Node* reverseLinkedList(Node* head) {
    Node* prev = NULL;    
    Node* curr = head;     
    Node* next = NULL;     

    while (curr != NULL) {
        next = curr->next;  
        curr->next = prev;  
        prev = curr;        
        curr = next;        
    }

    return prev;            
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

