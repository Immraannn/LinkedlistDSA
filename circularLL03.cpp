#include <iostream>      // for input-output
#include <map>           // for map used in loop detection
using namespace std;     // to avoid std:: prefix

// Node class representing each element of the linked list
class Node {
public:
    int data;            // data stored in the node
    Node* next;          // pointer to the next node

    // Constructor to initialize node
    Node(int d) {
        data = d;        // assign data
        next = NULL;     // initialize next as NULL
    }

    // Destructor (IMPORTANT: does NOT delete next)
    ~Node() {
        cout << "Memory is free for node with data " << data << endl;
    }
};

// Function to insert a node in a circular linked list
void insertNode(Node* &tail, int element, int d) {

    // If list is empty
    if (tail == NULL) {

        Node* newNode = new Node(d);   // create new node
        tail = newNode;               // tail points to new node
        newNode->next = newNode;      // circular link (points to itself)
    }
    else {

        // Start traversal from tail
        Node* curr = tail;

        // Traverse until element is found
        do {
            if (curr->data == element)
                break;                // element found
            curr = curr->next;        // move to next node
        } while (curr != tail);

        // Insert new node after found element
        Node* temp = new Node(d);     // create new node
        temp->next = curr->next;      // new node points to next node
        curr->next = temp;            // current node points to new node
    }
}

// Function to print circular linked list
void print(Node* tail) {

    // If list is empty
    if (tail == NULL) {
        cout << "List is Empty" << endl;
        return;
    }

    Node* curr = tail;                // start from tail

    // Traverse circular list
    do {
        cout << curr->data << " ";    // print data
        curr = curr->next;            // move to next node
    } while (curr != tail);            // stop when full circle completes

    cout << endl;                     // new line
}

// Function to delete a node from circular linked list
void deleteNode(Node* &tail, int value) {

    // If list is empty
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* prev = tail;                // previous node
    Node* curr = tail->next;          // current node

    // Traverse until value is found
    while (curr->data != value) {
        prev = curr;                  // move prev
        curr = curr->next;            // move curr
    }

    // Single node case
    if (curr == prev) {
        tail = NULL;                  // list becomes empty
    }
    // If deleting tail node
    else if (curr == tail) {
        tail = prev;                  // update tail
    }

    prev->next = curr->next;          // bypass the node
    curr->next = NULL;                // disconnect node
    delete curr;                      // delete node
}

// Function to check if linked list is circular
bool isCircularList(Node* head) {

    // Empty list is circular
    if (head == NULL)
        return true;

    Node* temp = head->next;          // start from next node

    // Traverse list
    while (temp != NULL && temp != head) {
        temp = temp->next;            // move forward
    }

    // If returned to head → circular
    return (temp == head);
}

// Function to detect loop using map (for normal linked list)
bool detectLoop(Node* head) {

    // If list is empty
    if (head == NULL)
        return false;

    map<Node*, bool> visited;          // map to track visited nodes
    Node* temp = head;                // start from head

    // Traverse list
    while (temp != NULL) {

        // If node already visited → loop exists
        if (visited[temp] == true)
            return true;

        visited[temp] = true;         // mark node visited
        temp = temp->next;            // move forward
    }

    return false;                     // no loop found
}

// Main function
int main() {

    Node* tail = NULL;                // initialize empty list

    // Insert nodes
    insertNode(tail, 0, 3);            // insert first node
    insertNode(tail, 3, 5);            // insert after 3
    insertNode(tail, 5, 7);            // insert after 5
    insertNode(tail, 7, 9);            // insert after 7

    // Print list
    print(tail);

    // Delete a node
    deleteNode(tail, 5);

    // Print list after deletion
    print(tail);

    // Check if list is circular
    if (isCircularList(tail))
        cout << "Linked List is Circular" << endl;
    else
        cout << "Linked List is NOT Circular" << endl;

    return 0;                          // end of program
}
