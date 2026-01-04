//ITERATIVE METHOD
#include<iostream>          // input-output library
using namespace std;        // standard namespace

// Node class for linked list
class Node {
public:
    int data;               // data part of node
    Node* next;             // pointer to next node

    Node(int d) {            // constructor
        data = d;            // assign data
        next = NULL;         // initialize next as NULL
    }
};

// Function to merge two sorted linked lists iteratively
Node* mergeTwoLists(Node* head1, Node* head2) {

    if(head1 == NULL)        // if first list is empty
        return head2;        // return second list

    if(head2 == NULL)        // if second list is empty
        return head1;        // return first list

    Node* head = NULL;       // head of merged linked list
    Node* tail = NULL;       // tail of merged linked list

    // Decide first node of merged list
    if(head1->data < head2->data) {   // compare first nodes
        head = head1;                  // head points to smaller node
        tail = head1;                  // tail also points to same node
        head1 = head1->next;           // move head1 forward
    } else {
        head = head2;                  // head points to smaller node
        tail = head2;                  // tail also points to same node
        head2 = head2->next;           // move head2 forward
    }

    // Traverse both linked lists
    while(head1 != NULL && head2 != NULL) {

        if(head1->data < head2->data) { // compare current nodes
            tail->next = head1;          // connect smaller node
            tail = head1;                // move tail forward
            head1 = head1->next;         // move head1 forward
        } else {
            tail->next = head2;          // connect smaller node
            tail = head2;                // move tail forward
            head2 = head2->next;         // move head2 forward
        }
    }

    // Attach remaining nodes of first list
    if(head1 != NULL)
        tail->next = head1;              // connect remaining nodes

    // Attach remaining nodes of second list
    else
        tail->next = head2;              // connect remaining nodes

    return head;                         // return merged list head
}



//RECURSIVE METHOD

// Function to merge two sorted linked lists using recursion
Node* mergeTwoLists(Node* head1, Node* head2) {

    if(head1 == NULL)          // if first list is empty
        return head2;          // return second list

    if(head2 == NULL)          // if second list is empty
        return head1;          // return first list

    if(head1->data < head2->data) {      // compare node values
        head1->next = mergeTwoLists(     // recursive call
            head1->next,                 // move head1 forward
            head2                         // keep head2 same
        );
        return head1;                    // return smaller node
    }
    else {
        head2->next = mergeTwoLists(     // recursive call
            head1,                        // keep head1 same
            head2->next                  // move head2 forward
        );
        return head2;                    // return smaller node
    }
}
