#include <iostream>                 
#include <map>                      
using namespace std;                
class Node {                       
public:                             
    int data;                       
    Node* next;                     
    Node(int data) {               
        this->data = data;          
        this->next = NULL;          
    }

    ~Node() {                      
        cout << "Memory freed for node with data "<< this->data << endl; 
    }
};

void insertAtHead(Node* &head, int d) {   
    Node* temp = new Node(d);     
    temp->next = head;              
    head = temp;                    
}

void insertAtTail(Node* &tail, int d) {   
    Node* temp = new Node(d);      
    tail->next = temp;             
    tail = temp;                   
}

void print(Node* head) {            
    if(head == NULL) {              
        cout << "List is empty" << endl; 
        return;                    
    }
    Node* temp = head;              
    while(temp != NULL) {          
        cout << temp->data << " ";  
        temp = temp->next;          
    }
    cout << endl;                  
}

int length(Node* head) {
    int cnt = 0;
    while (head != nullptr) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d) {
    if(position == 1) {            
        insertAtHead(head, d);     
        return;                    
    }

    Node* temp = head;              
    int cnt = 1;                   

    while(cnt < position - 1 && temp != NULL) { 
        temp = temp->next;         
        cnt++;                     
    }

    if(temp->next == NULL) {        
        insertAtTail(tail, d);      
        return;                     
    }
    Node* nodeToInsert = new Node(d); 
    nodeToInsert->next = temp->next;  
    temp->next = nodeToInsert;        
}

void deleteNode(int position, Node* &head) {

    if(head == NULL)              
        return;                     // Exit function

    if(position == 1) {             
        Node* temp = head;         
        head = head->next;          
        temp->next = NULL;         
        delete temp;               
        return;                     
    }

    Node* curr = head;             
    Node* prev = NULL;              
    int cnt = 1;                   

    while(curr != NULL && cnt < position) { 
        prev = curr;                // Store previous node
        curr = curr->next;          // Move current forward
        cnt++;                      // Increment counter
    }

    if(curr == NULL)                // If position is invalid
        return;                     // Exit function

    prev->next = curr->next;        // Bypass the current node
    curr->next = NULL;              // Disconnect current node
    delete curr;                    // Delete current node
}

bool isCircular(Node* head) {
    if (head == nullptr)
        return true;
    Node* curr = head;
    while (curr->next != nullptr) {
        if (curr->next == head)
            return true;
        curr = curr->next;
    }
    return false;
}


bool detectLoop(Node* head) {

    if (head == nullptr)
        return false;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          
        fast = fast->next->next;   
        if (slow == fast)
            return true;
    }
    return false;
}

Node* floydDetectLoop(Node* head) {

    if(head == NULL)                
        return NULL;               
    Node* slow = head;              
    Node* fast = head;              
    while(fast != NULL && fast->next != NULL) { 

        slow = slow->next;         
        fast = fast->next->next;   

        if(slow == fast)           
            return slow;           
    }
    return NULL;                  
}

// FIND START OF LOOP
Node* getStartingNode(Node* head) {
    if(head == NULL)               
        return NULL;              
    Node* intersection = floydDetectLoop(head); 
    if(intersection == NULL)        
        return NULL;                
    Node* slow = head;             
    while(slow != intersection) {   
        slow = slow->next;        
        intersection = intersection->next; 
    }
    return slow;                   
}

//  REMOVE LOOP
void removeLoop(Node* head) {
    if(head == NULL)                
        return;                   
    Node* startOfLoop = getStartingNode(head); // Get loop start
    if(startOfLoop == NULL)         // If no loop
        return;                     // Exit
    Node* temp = startOfLoop;       // Start from loop node
    while(temp->next != startOfLoop) { // Reach last loop node
        temp = temp->next;          // Move forward
    }

    temp->next = NULL;              // Break the loop
}

int main() {

    Node* node1 = new Node(10);     // Create first node

    Node* head = node1;             // Head points to first node
    Node* tail = node1;             // Tail points to first node

    insertAtTail(tail, 12);         // Insert 12 at tail
    insertAtTail(tail, 15);         // Insert 15 at tail
    insertAtPosition(tail, head, 4, 22); // Insert 22 at position 4

    tail->next = head->next;        // Create loop manually

    if(floydDetectLoop(head))       // Check for loop
        cout << "Cycle is present" << endl;
    else
        cout << "No cycle" << endl;

    removeLoop(head);               // Remove loop from list

    print(head);                    // Print final list

    return 0;                       // End of program
}
