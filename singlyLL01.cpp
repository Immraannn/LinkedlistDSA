#include <iostream>                 // Header file for input-output
#include <map>                      // Header file for map (used in loop detection)
using namespace std;                // To avoid writing std:: repeatedly

// ===================== NODE CLASS =====================
class Node {                        // Class representing a node of linked list
public:                             // Public access specifier
    int data;                       // Variable to store node data
    Node* next;                     // Pointer to next node

    Node(int data) {                // Constructor of Node class
        this->data = data;          // Assign value to data of node
        this->next = NULL;          // Initialize next pointer as NULL
    }

    ~Node() {                       // Destructor of Node class
        cout << "Memory freed for node with data "
             << this->data << endl; // Print message when node is deleted
    }
};

// ===================== INSERT AT HEAD =====================
void insertAtHead(Node* &head, int d) {   // Function to insert node at head

    Node* temp = new Node(d);       // Create a new node with data d
    temp->next = head;              // New node points to current head
    head = temp;                    // Head now points to new node
}

// ===================== INSERT AT TAIL =====================
void insertAtTail(Node* &tail, int d) {   // Function to insert node at tail

    Node* temp = new Node(d);       // Create a new node with data d
    tail->next = temp;              // Current tail points to new node
    tail = temp;                    // Update tail to new node
}

// ===================== PRINT LINKED LIST =====================
void print(Node* head) {            // Function to print linked list

    if(head == NULL) {              // If list is empty
        cout << "List is empty" << endl; // Print message
        return;                     // Exit function
    }

    Node* temp = head;              // Temporary pointer starting at head

    while(temp != NULL) {           // Loop till end of list
        cout << temp->data << " ";  // Print current node data
        temp = temp->next;          // Move to next node
    }
    cout << endl;                   // New line after printing list
}


int length(Node* head) {

    int cnt = 0;

    while (head != nullptr) {

        cnt++;

        head = head->next;
    }

    return cnt;
}

// ===================== INSERT AT POSITION =====================
void insertAtPosition(Node* &tail, Node* &head, int position, int d) {

    if(position == 1) {             // If position is first
        insertAtHead(head, d);      // Insert at head
        return;                     // Exit function
    }

    Node* temp = head;              // Pointer to traverse list
    int cnt = 1;                    // Counter variable

    while(cnt < position - 1 && temp != NULL) { // Traverse till (position-1)
        temp = temp->next;          // Move temp forward
        cnt++;                      // Increment counter
    }

    if(temp->next == NULL) {        // If inserting at end
        insertAtTail(tail, d);      // Insert at tail
        return;                     // Exit function
    }

    Node* nodeToInsert = new Node(d); // Create new node

    nodeToInsert->next = temp->next;  // New node points to next node
    temp->next = nodeToInsert;        // Previous node points to new node
}

// ===================== DELETE NODE =====================
void deleteNode(int position, Node* &head) {

    if(head == NULL)                // If list is empty
        return;                     // Exit function

    if(position == 1) {             // If deleting first node
        Node* temp = head;          // Store current head
        head = head->next;          // Move head to next node
        temp->next = NULL;          // Disconnect node
        delete temp;                // Delete node
        return;                     // Exit function
    }

    Node* curr = head;              // Pointer to current node
    Node* prev = NULL;              // Pointer to previous node
    int cnt = 1;                    // Counter variable

    while(curr != NULL && cnt < position) { // Traverse to position
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

// ===================== CHECK CIRCULAR LIST =====================
bool isCircularList(Node* head) {

    if(head == NULL)                // Empty list is circular
        return true;                // Return true

    Node* temp = head->next;        // Start from second node

    while(temp != NULL && temp != head) { // Traverse list
        temp = temp->next;          // Move to next node
    }

    return (temp == head);          // True if circular
}

// ===================== LOOP DETECTION (MAP METHOD) =====================
bool detectLoop(Node* head) {

    if(head == NULL)                // If list is empty
        return false;               // No loop

    map<Node*, bool> visited;       // Map to track visited nodes
    Node* temp = head;              // Start traversal from head

    while(temp != NULL) {           // Traverse list

        if(visited[temp]) {         // If node already visited 
            cout << "Loop present at node "
                 << temp->data << endl; // Print loop info
            return true;            // Loop detected
        }
       //  The logic is:Check whether the current node has already been visited.
       //  If yes → loop found.
       //  Otherwise, mark it as visited.
       // Move to the next node.

        visited[temp] = true;       // Mark node as visited
        temp = temp->next;          // Move to next node
    }
    return false;                   // No loop found
}

// ===================== FLOYD CYCLE DETECTION =====================
Node* floydDetectLoop(Node* head) {

    if(head == NULL)                // If list is empty
        return NULL;                // No loop

    Node* slow = head;              // Slow pointer (1 step)
    Node* fast = head;              // Fast pointer (2 steps)

    while(fast != NULL && fast->next != NULL) { // Valid movement

        slow = slow->next;          // Move slow by one step
        fast = fast->next->next;   // Move fast by two steps

        if(slow == fast)            // If pointers meet
            return slow;            // Loop detected
    }
    return NULL;                    // No loop
}

// ===================== FIND START OF LOOP =====================
Node* getStartingNode(Node* head) {

    if(head == NULL)                // If list is empty
        return NULL;                // No start

    Node* intersection = floydDetectLoop(head); // Detect loop
    if(intersection == NULL)        // If no loop
        return NULL;                // Return NULL

    Node* slow = head;              // Pointer from head

    while(slow != intersection) {   // Move both pointers
        slow = slow->next;          // Move slow by one
        intersection = intersection->next; // Move intersection by one
    }

    return slow;                    // Starting node of loop
}

// ===================== REMOVE LOOP =====================
void removeLoop(Node* head) {

    if(head == NULL)                // If list is empty
        return;                     // Exit

    Node* startOfLoop = getStartingNode(head); // Get loop start
    if(startOfLoop == NULL)         // If no loop
        return;                     // Exit

    Node* temp = startOfLoop;       // Start from loop node

    while(temp->next != startOfLoop) { // Reach last loop node
        temp = temp->next;          // Move forward
    }

    temp->next = NULL;              // Break the loop
}

// ===================== MAIN FUNCTION =====================
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
