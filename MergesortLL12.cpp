#include <iostream>
using namespace std;

/*
    Node structure for Singly Linked List
*/
class Node {
public:
    int data;        // stores data
    Node* next;      // pointer to next node

    // Constructor
    Node(int d) {
        data = d;    // assign data
        next = NULL; // initialize next as NULL
    }
};

/*
    Function to print linked list
*/
void printList(Node* head) {

    Node* temp = head;          // start from head

    while (temp != NULL) {      // traverse till end
        cout << temp->data << " ";
        temp = temp->next;      // move to next node
    }

    cout << endl;
}

/*
    Find middle of linked list using slow-fast method
*/
Node* findMid(Node* head) {

    Node* slow = head;          // slow moves 1 step
    Node* fast = head->next;    // fast moves 2 steps

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;      // move slow
        fast = fast->next->next;// move fast
    }

    return slow;                // slow is middle
}

/* ==========================================================
   ITERATIVE MERGE FUNCTION (RENAMED VARIABLE)
   ========================================================== */
Node* mergeIterative(Node* left, Node* right) {

    Node* dummy = new Node(-1); // dummy node (temporary head)
    Node* current = dummy;     // current points to last merged node

    // loop while both lists have nodes
    while (left != NULL && right != NULL) {

        if (left->data <= right->data) {
            current->next = left;   // attach left node
            left = left->next;      // move left pointer
        }
        else {
            current->next = right;  // attach right node
            right = right->next;    // move right pointer
        }

        current = current->next;    // move current forward
    }

    // attach remaining nodes of left list (if any)
    if (left != NULL) {
        current->next = left;
    }

    // attach remaining nodes of right list (if any)
    if (right != NULL) {
        current->next = right;
    }

    Node* result = dummy->next; // actual head of merged list
    delete dummy;               // delete dummy node

    return result;              // return sorted merged list
}

/* ==========================================================
   RECURSIVE MERGE FUNCTION
   ========================================================== */
Node* mergeRecursive(Node* left, Node* right) {

    // if left list is empty
    if (left == NULL) {
        return right;
    }

    // if right list is empty
    if (right == NULL) {
        return left;
    }

    Node* result = NULL;        // pointer to merged list

    if (left->data <= right->data) {
        result = left;          // choose left node
        result->next = mergeRecursive(left->next, right);
    }
    else {
        result = right;         // choose right node
        result->next = mergeRecursive(left, right->next);
    }

    return result;              // return merged list
}

/*
    Merge Sort function
*/
Node* mergeSort(Node* head) {

    // base case
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* mid = findMid(head);  // find middle

    Node* left = head;          // left half
    Node* right = mid->next;    // right half

    mid->next = NULL;           // break list into two parts

    // recursive sorting
    left = mergeSort(left);
    right = mergeSort(right);

    // merge sorted halves
    return mergeIterative(left, right); 
    // OR use: mergeRecursive(left, right);
}

/*
    Main function
*/
int main() {

    // create list: 4 -> 2 -> 1 -> 3
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    cout << "Original List: ";
    printList(head);

    head = mergeSort(head);     // sort list

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
