#include<iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

// Function to add two numbers represented by linked lists
Node* addTwoLists(Node* first, Node* second) {

    Node* dummy = new Node(0);   // dummy node to simplify logic
    Node* temp = dummy;          // pointer to build result list
    int carry = 0;               // carry initialization

    // Loop until both lists end and no carry remains
    while (first != NULL || second != NULL || carry != 0) {

        int sum = carry;         // start with carry

        if (first != NULL) {
            sum += first->data;  // add first list digit
            first = first->next;
        }

        if (second != NULL) {
            sum += second->data; // add second list digit
            second = second->next;
        }

        carry = sum / 10;        // calculate carry
        int digit = sum % 10;    // extract last digit

        temp->next = new Node(digit); // create new node
        temp = temp->next;            // move pointer
    }

    return dummy->next;          // return result list
}


//RECURSIVE METHO
Node* add(Node* l1, Node* l2, int carry) {

    // Base case: no nodes left and no carry
    if (l1 == NULL && l2 == NULL && carry == 0) {
        return NULL;
    }

    int sum = carry;   // start with carry

    // add l1 digit if exists
    if (l1 != NULL)
        sum += l1->data;

    // add l2 digit if exists
    if (l2 != NULL)
        sum += l2->data;

    int digit = sum % 10;   // digit for current node
    int newCarry = sum / 10; // carry for next recursion

    // create current node
    Node* result = new Node(digit);

    // recursive call for next nodes
    result->next = add(
        (l1 != NULL) ? l1->next : NULL,
        (l2 != NULL) ? l2->next : NULL,
        newCarry
    );

    return result; // return permanent head of this sub-list
}

