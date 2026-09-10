// Function to reverse a linked list
Node* reverse(Node* head) {
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

bool isPalindrome(Node* head) {

    if (head == NULL || head->next == NULL)
        return true;            

    Node* slow = head;           
    Node* fast = head;           
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;      
        fast = fast->next->next;
    }
    // Reverse second half of the list
    Node* secondHalf = reverse(slow);

    Node* firstHalf = head;      
    Node* temp = secondHalf;    
    while (temp != NULL) {

        if (firstHalf->data != temp->data)
            return false;         

        firstHalf = firstHalf->next; 
        temp = temp->next;           
    }

    return true;                 
}
