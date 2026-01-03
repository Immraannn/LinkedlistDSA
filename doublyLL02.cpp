#include<iostream>          // For input-output operations
using namespace std;       // To avoid using std:: repeatedly

/*
    Node class for Doubly Linked List
*/
class Node {
public:
    int data;              // Stores data of the node
    Node* prev;            // Pointer to previous node
    Node* next;            // Pointer to next node

    // Constructor: initializes a new node
    Node(int d) {
        data = d;          // Assign value to data
        prev = NULL;       // Previous pointer initially NULL
        next = NULL;       // Next pointer initially NULL
    }

    // Destructor (safe: does NOT delete next or prev)
    ~Node() {
        // Only used to show when node memory is freed
        cout << "Memory freed for node with data " << data << endl;
    }
};

/*
    Function to print the doubly linked list
*/
void print(Node* head) {
    Node* temp = head;     // Start traversal from head

    while (temp != NULL) { // Traverse till last node
        cout << temp->data << " "; // Print current node data
        temp = temp->next;         // Move to next node
    }
    cout << endl;          // New line after printing list
}

/*
    Function to return length of linked list
*/
int getLength(Node* head) {
    int len = 0;           // Counter for nodes
    Node* temp = head;     // Start from head

    while (temp != NULL) { // Traverse entire list
        len++;             // Increase length count
        temp = temp->next;// Move to next node
    }
    return len;            // Return total length
}

/*
    Insert a node at the head (beginning)
*/
void insertAtHead(Node* &head, Node* &tail, int d) {

    if (head == NULL) {        // If list is empty
        Node* temp = new Node(d); // Create new node
        head = temp;           // Head points to new node
        tail = temp;           // Tail also points to new node
    }
    else {                     // If list is not empty
        Node* temp = new Node(d); // Create new node
        temp->next = head;     // New node points to old head
        head->prev = temp;     // Old head points back to new node
        head = temp;           // Update head
    }
}

/*
    Insert a node at the tail (end)
*/
void insertAtTail(Node* &head, Node* &tail, int d) {

    if (tail == NULL) {        // If list is empty
        Node* temp = new Node(d);
        head = temp;           // Head points to new node
        tail = temp;           // Tail points to new node
    }
    else {                     // If list is not empty
        Node* temp = new Node(d);
        tail->next = temp;     // Old tail points to new node
        temp->prev = tail;     // New node points back to old tail
        tail = temp;           // Update tail
    }
}

/*
    Insert a node at a given position (1-based index)
*/
void insertAtPosition(Node* &head, Node* &tail, int position, int d) {

    if (position == 1) {       // If inserting at first position
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;         // Start traversal from head
    int cnt = 1;               // Position counter

    // Move to (position-1)th node safely
    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) return; // Invalid position

    if (temp->next == NULL) { // If inserting at last position
        insertAtTail(head, tail, d);
        return;
    }

    // Insert in middle
    Node* nodeToInsert = new Node(d); // Create new node
    nodeToInsert->next = temp->next; // New node points to next node
    temp->next->prev = nodeToInsert; // Next node points back to new node
    temp->next = nodeToInsert;       // Current node points to new node
    nodeToInsert->prev = temp;       // New node points back to current node
}

/*
    Delete node at a given position
*/
void deleteNode(int position, Node* &head, Node* &tail) {

    if (head == NULL) return;  // If list is empty

    // Case 1: Delete first node
    if (position == 1) {
        Node* temp = head;     // Store current head

        if (head->next == NULL) { // If only one node exists
            head = NULL;
            tail = NULL;
        }
        else {                 // If more than one node
            head = head->next; // Move head forward
            head->prev = NULL;// New head has no previous
        }

        temp->next = NULL;    // Disconnect node
        delete temp;          // Delete node
        return;
    }

    // Case 2: Delete middle or last node
    Node* curr = head;        // Current node pointer
    Node* prev = NULL;        // Previous node pointer
    int cnt = 1;              // Position counter

    // Traverse to desired position
    while (cnt < position && curr != NULL) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    if (curr == NULL) return;// Invalid position

    if (curr->next == NULL) { // If deleting last node
        prev->next = NULL;    // Previous node becomes last
        tail = prev;          // Update tail
    }
    else {                    // If deleting middle node
        prev->next = curr->next;
        curr->next->prev = prev;
    }

    curr->prev = NULL;        // Disconnect current node
    curr->next = NULL;
    delete curr;              // Delete node
}

/*
    MAIN FUNCTION
*/
int main() {

    Node* head = NULL;        // Head pointer
    Node* tail = NULL;        // Tail pointer

    insertAtHead(head, tail, 11);
    insertAtHead(head, tail, 13);
    insertAtHead(head, tail, 8);
    insertAtTail(head, tail, 25);

    print(head);
    // Output: 8 13 11 25

    insertAtPosition(head, tail, 2, 100);
    print(head);
    // Output: 8 100 13 11 25

    insertAtPosition(head, tail, 1, 101);
    print(head);
    // Output: 101 8 100 13 11 25

    insertAtPosition(head, tail, 7, 102);
    print(head);
    // Output: 101 8 100 13 11 25 102

    deleteNode(1, head, tail);
    print(head);
    // Output: 8 100 13 11 25 102

    deleteNode(3, head, tail);
    print(head);
    // Output: 8 100 11 25 102

    deleteNode(getLength(head), head, tail);
    print(head);
    // Output: 8 100 11 25

    cout << "Head: " << (head ? head->data : -1) << endl;
    cout << "Tail: " << (tail ? tail->data : -1) << endl;
    // Output:
    // Head: 8
    // Tail: 25

    return 0;                // Program ends
}
