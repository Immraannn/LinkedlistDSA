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
void removeDuplicates(Node* head)
{
    unordered_map<int, bool> visited;
    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL)
    {
        // If current value was already seen
        if(visited[curr->data] == true)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            // First time seeing this value
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
}
