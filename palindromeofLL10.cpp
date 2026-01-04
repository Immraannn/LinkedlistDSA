#include <iostream>              // Include input-output stream library
using namespace std;             // Use standard namespace

// Node class for linked list
class Node {
public:
    int data;                    // Stores value of node
    Node* next;                  // Pointer to next node

    // Constructor to initialize node
    Node(int d) {
        data = d;                // Assign data
        next = NULL;             // Initialize next as NULL
    }
};

// Function to reverse a linked list
Node* reverse(Node* head) {

    Node* prev = NULL;           // Previous pointer initially NULL
    Node* curr = head;           // Current pointer starts from head
    Node* next = NULL;           // Next pointer to store next node

    // Loop until current becomes NULL
    while (curr != NULL) {

        next = curr->next;       // Store address of next node
        curr->next = prev;       // Reverse the link
        prev = curr;             // Move prev one step ahead
        curr = next;             // Move curr one step ahead
    }

    return prev;                 // Return new head of reversed list
}

// Function to check whether linked list is palindrome
bool isPalindrome(Node* head) {

    // If list is empty or has only one node
    if (head == NULL || head->next == NULL)
        return true;             // It is a palindrome

    Node* slow = head;           // Slow pointer starts from head
    Node* fast = head;           // Fast pointer starts from head

    // Move slow by 1 step and fast by 2 steps
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;       // Move slow pointer by one node
        fast = fast->next->next;// Move fast pointer by two nodes
    }

    // Reverse second half of the list
    Node* secondHalf = reverse(slow->next);

    Node* firstHalf = head;      // Pointer for first half
    Node* temp = secondHalf;     // Pointer for second half

    // Compare both halves
    while (temp != NULL) {

        if (firstHalf->data != temp->data) // If data mismatch
            return false;         // Not a palindrome

        firstHalf = firstHalf->next; // Move first half pointer
        temp = temp->next;            // Move second half pointer
    }

    return true;                 // Palindrome confirmed
}

// Main function
int main() {

    // Creating linked list: 1 -> 2 -> 3 -> 2 -> 1
    Node* head = new Node(1);                        // First node
    head->next = new Node(2);                        // Second node
    head->next->next = new Node(3);                  // Third node
    head->next->next->next = new Node(2);            // Fourth node
    head->next->next->next->next = new Node(1);      // Fifth node

    // Check palindrome and print result
    if (isPalindrome(head))                          // Call function
        cout << "Linked List is Palindrome" << endl; // Output if true
    else
        cout << "Linked List is NOT Palindrome" << endl; // Output if false

    return 0;                                        // End program
}
