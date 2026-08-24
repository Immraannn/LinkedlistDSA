class Solution {
public:
    Node* mergeTwoLists(Node* list1, Node* list2) {
        // Create a dummy node
        Node* dummy = new Node(-1);
        // Tail always points to the last node of merged list
        Node* tail = dummy;
        // Merge until one list becomes empty
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        // Attach remaining nodes
        if (list1 != nullptr)
            tail->next = list1;
        else
            tail->next = list2;
        // First real node
        Node* head = dummy->next;
        delete dummy;
        return head;
    }
};



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
