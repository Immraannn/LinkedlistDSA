// Function to remove duplicates from sorted linked list
Node* removeDuplicates(Node* head) {
    if (head == NULL) {
        return head;
    }
    Node* curr = head;   
    while (curr != NULL && curr->next != NULL) {
        if (curr->data == curr->next->data) {
            Node* temp = curr->next;     
            curr->next = temp->next;     
            delete temp;                 
        }
        else {
            curr = curr->next;           
        }
    }
   return head;  
}
// Function to remove duplicates from UNSORTED linked list
Node* removeDuplicates(Node* head) {
    if (head == NULL) {
        return head;
    }
    map<int, bool> visited;   // map to track visited values
    Node* curr = head;        // current node
    Node* prev = NULL;        // previous node
    while (curr != NULL) {
        // if data already visited
        if (visited[curr->data] == true) {
            Node* temp = curr;         // store duplicate node
            prev->next = curr->next;   // bypass duplicate
            curr = curr->next;         // move curr forward
            delete temp;               // delete duplicate node
        }
        else {
            visited[curr->data] = true; // mark data as visited
            prev = curr;                // move prev
            curr = curr->next;          // move curr
        }
    }

    return head;  // return updated head
}

