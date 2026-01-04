//METHOD 1: COUNTING METHOD (Data Replacement)

#include<iostream>                 // For input-output operations
using namespace std;

// Definition of Node class
class Node {
public:
    int data;                      // Stores value (0 or 1)
    Node* next;                    // Pointer to next node

    Node(int d) {                  // Constructor
        data = d;                  // Assign data
        next = NULL;               // Initialize next as NULL
    }
};

void sortZeroOne(Node* head) {     
    int count0 = 0;                // Counter for number of 0s
    int count1 = 0;                // Counter for number of 1s

    Node* temp = head;             // Temporary pointer to traverse list

    // First traversal: count number of 0s and 1s
    while(temp != NULL) {          
        if(temp->data == 0)        // If node data is 0
            count0++;              // Increment count0
        else                       // Otherwise data is 1
            count1++;              // Increment count1
        temp = temp->next;         // Move to next node
    }

    temp = head;                   // Reset temp to head

    // Fill all 0s first
    while(count0--) {              
        temp->data = 0;            // Assign 0
        temp = temp->next;         // Move to next node
    }

    // Fill remaining nodes with 1
    while(count1--) {              
        temp->data = 1;            // Assign 1
        temp = temp->next;         // Move to next node
    }
}



METHOD 2: LINK CHANGING METHOD (NO DATA MODIFICATION)

Node* sortZeroOne(Node* head) {

    // Dummy head for list containing 0s
    Node* zeroHead = new Node(-1);

    // Dummy head for list containing 1s
    Node* oneHead = new Node(-1);

    // Tail pointer for 0 list
    Node* zeroTail = zeroHead;

    // Tail pointer for 1 list
    Node* oneTail = oneHead;

    // Pointer to traverse original list
    Node* curr = head;

    // Traverse original linked list
    while(curr != NULL) {

        if(curr->data == 0) {              // If current node contains 0
            zeroTail->next = curr;         // Attach node to zero list
            zeroTail = curr;               // Move zeroTail forward
        }
        else {                             // If current node contains 1
            oneTail->next = curr;          // Attach node to one list
            oneTail = curr;                // Move oneTail forward
        }

        curr = curr->next;                 // Move to next node
    }

    // Connect zero list with one list
    zeroTail->next = oneHead->next;

    // Mark end of list
    oneTail->next = NULL;

    // Update head to start of sorted list
    head = zeroHead->next;

    // Delete dummy nodes to avoid memory leak
    delete zeroHead;
    delete oneHead;

    return head;                           // Return new head
}
