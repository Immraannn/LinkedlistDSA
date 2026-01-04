//FOR SORTED LINKEDLIST
#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;          // data part
    Node* next;        // pointer to next node

    // constructor
    Node(int d) {
        data = d;      // assign data
        next = NULL;   // initialize next as NULL
    }
};

// Function to remove duplicates from sorted linked list
Node* removeDuplicates(Node* head) {

    // if list is empty
    if (head == NULL) {
        return head;
    }

    Node* curr = head;   // start from head

    // traverse the list
    while (curr != NULL && curr->next != NULL) {

        // if current and next node have same data
        if (curr->data == curr->next->data) {

            Node* temp = curr->next;     // store duplicate node
            curr->next = temp->next;     // bypass duplicate
            delete temp;                 // delete duplicate node
        }
        else {
            curr = curr->next;           // move to next node
        }
    }

    return head;  // return updated head
}


//FOR UNSORTED LL

#include <iostream>
#include <map>
using namespace std;

// Node structure
class Node {
public:
    int data;        // data part
    Node* next;      // pointer to next node

    // constructor
    Node(int d) {
        data = d;    // assign data
        next = NULL; // initialize next
    }
};

// Function to remove duplicates from UNSORTED linked list
Node* removeDuplicates(Node* head) {

    // empty list check
    if (head == NULL) {
        return head;
    }

    map<int, bool> visited;   // map to track visited values

    Node* curr = head;        // current node
    Node* prev = NULL;        // previous node

    // traverse the list
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

