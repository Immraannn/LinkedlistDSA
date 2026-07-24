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

//********************************CONCEPT******************************
// Create a dummy node.
// It is a permanent starting node for the new linked list.
//Node* dummy = new Node(-1);
// curr and dummy both point to the SAME node.
// No new node is created here.
// Only the address is copied.
//Node* curr = dummy;
/*
Memory:
dummy
  |
  v
[-1] -> NULL
  ^
  |
 curr
*/
// Add a new node after curr.
//curr->next = new Node(10);
/*
Since curr and dummy point to the same node,
curr->next and dummy->next refer to the same next pointer.
Memory:
dummy
  |
  v
[-1] -> [10] -> NULL
  ^
  |
 curr
*/
// Move curr to the newly added node.
//curr = curr->next;
/*
Only curr moves.
dummy stays at the first node.
Memory:
dummy
  |
  v
[-1] -> [10] -> NULL
          ^
          |
         curr
*/
// Add another node after curr.
//curr->next = new Node(20);
/*
Memory:
dummy
  |
  v
[-1] -> [10] -> [20] -> NULL
                    ^
                    |
                   curr
The linked list is still connected to dummy.
curr simply helps us build the list.
*/
// At the end, skip the dummy node.
//return dummy->next;
/*
Why dummy?
1. Avoids special handling for the first node.
2. We never lose the head of the new linked list.
3. curr keeps moving while dummy always stays at the beginning.
4. Since curr initially points to dummy, any changes through curr
   automatically become part of the list starting from dummy.
Important:
Node* curr = dummy;
DOES NOT create a copy of the linked list.
It only copies the ADDRESS.

Both pointers refer to the same node until curr is moved.
*/
