#include <iostream>              // for input-output operations
using namespace std;

// Node class for linked list
class Node {
public:
    int data;                    // data part of node
    Node* next;                  // pointer to next node

    // constructor to initialize node
    Node(int d) {
        data = d;                // assign value to data
        next = NULL;             // initialize next as NULL
    }
};

// function to insert node at tail of linked list
void insertAtTail(Node* &head, int d) {

    // if list is empty
    if(head == NULL) {
        head = new Node(d);      // create first node
        return;                  // exit function
    }

    Node* temp = head;           // temp pointer starts from head

    // traverse till last node
    while(temp->next != NULL) {
        temp = temp->next;       // move temp forward
    }

    temp->next = new Node(d);    // attach new node at end
}

// function to find middle of linked list
Node* getMiddle(Node* head) {

    // if linked list is empty
    if(head == NULL)
        return NULL;             // no middle exists

    Node* slow = head;           // slow pointer starts at head
    Node* fast = head;           // fast pointer starts at head

    // move fast by 2 and slow by 1
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;       // move slow one step
        fast = fast->next->next;// move fast two steps
    }

    return slow;                 // slow points to middle node
}

// function to print linked list
void printList(Node* head) {

    Node* temp = head;           // start traversal from head

    while(temp != NULL) {
        cout << temp->data << " "; // print node data
        temp = temp->next;       // move to next node
    }

    cout << endl;                // new line after printing list
}

int main() {

    Node* head = NULL;           // initialize head as NULL

    // inserting elements into linked list
    insertAtTail(head, 10);      // insert 10
    insertAtTail(head, 20);      // insert 20
    insertAtTail(head, 30);      // insert 30
    insertAtTail(head, 40);      // insert 40
    insertAtTail(head, 50);      // insert 50

    cout << "Linked List: ";
    printList(head);             // print entire list

    // find middle node
    Node* mid = getMiddle(head); // receive slow pointer

    // if middle exists
    if(mid != NULL) {
        cout << "Middle node data: " << mid->data << endl;
    }

    return 0;                    // program ends successfully
}
