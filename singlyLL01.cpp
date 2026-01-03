#include<iostream>      // for input-output
#include<map>           // for map used in loop detection
using namespace std;

// ===================== NODE CLASS =====================
class Node {

public:
    int data;           // stores data of node
    Node* next;         // pointer to next node

    // -------- Constructor --------
    Node(int data) {
        this->data = data;   // assign data to node
        this->next = NULL;   // initially next is NULL
    }

    // -------- Destructor --------
    ~Node() {
        int value = this->data;   // store data for printing

        // if next node exists, delete it (DANGEROUS)
        if(this->next != NULL) {
            delete next;          // deletes remaining list
            this->next = NULL;    // avoid dangling pointer
        }

        cout << " memory is free for node with data " 
             << value << endl;
    }
};

// ===================== INSERT AT HEAD =====================
void insertAtHead(Node* &head, int d) {

    Node* temp = new Node(d); // create new node
    temp->next = head;        // new node points to old head
    head = temp;              // head moves to new node
}

// ===================== INSERT AT TAIL =====================
void insertAtTail(Node* &tail, int d) {

    Node* temp = new Node(d); // create new node
    tail->next = temp;        // old tail points to new node
    tail = temp;              // update tail
}

// ===================== PRINT LINKED LIST =====================
void print(Node* &head) {

    if(head == NULL) {        // if list empty
        cout << "List is empty "<< endl;
        return;
    }

    Node* temp = head;        // start from head

    while(temp != NULL) {     // traverse till end
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ===================== INSERT AT POSITION =====================
void insertAtPosition(Node* &tail, Node* &head, int position, int d) {

    // insert at first position
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    // move temp to (position-1)th node
    while(cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    // if inserting at last position
    if(temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    // create new node
    Node* nodeToInsert = new Node(d);

    // link new node
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// ===================== DELETE NODE =====================
void deleteNode(int position, Node* &head) {

    // deleting first node
    if(position == 1) {
        Node* temp = head;        // store head
        head = head->next;        // move head
        temp->next = NULL;        // disconnect
        delete temp;              // delete node
    }
    else {
        Node* curr = head;        // current node
        Node* prev = NULL;        // previous node

        int cnt = 1;
        while(cnt < position) {   // reach node to delete
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;  // bypass curr
        curr->next = NULL;        // disconnect
        delete curr;              // delete node
    }
}

// ===================== CHECK CIRCULAR LIST =====================
bool isCircularList(Node* head) {

    if(head == NULL)              // empty list
        return true;

    Node* temp = head->next;

    while(temp != NULL && temp != head) {
        temp = temp->next;
    }

    return (temp == head);
}

// ===================== LOOP DETECTION (MAP METHOD) =====================
bool detectLoop(Node* head) {

    if(head == NULL)
        return false;

    map<Node*, bool> visited;     // stores visited nodes
    Node* temp = head;

    while(temp != NULL) {

        if(visited[temp] == true) {  // loop detected
            cout << "Present on element " 
                 << temp->data << endl;
            return true;
        }

        visited[temp] = true;     // mark visited
        temp = temp->next;
    }
    return false;
}

// ===================== FLOYD CYCLE DETECTION =====================
Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;    // moves 1 step
    Node* fast = head;    // moves 2 steps

    while(slow != NULL && fast != NULL) {

        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;

        slow = slow->next;

        if(slow == fast) {   // meeting point
            cout << "present at " 
                 << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}

// ===================== FIND START OF LOOP =====================
Node* getStartingNode(Node* head) {

    if(head == NULL)
        return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;    // start of loop
}

// ===================== REMOVE LOOP =====================
void removeLoop(Node* head) {

    if(head == NULL)
        return;

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp->next != startOfLoop) {
        temp = temp->next;
    }

    temp->next = NULL;   // break loop
}

// ===================== MAIN FUNCTION =====================
int main() {

    Node* node1 = new Node(10);  // create first node

    Node* head = node1;          // head points to first node
    Node* tail = node1;          // tail also points to first

    insertAtTail(tail, 12);      // 10 -> 12
    insertAtTail(tail, 15);      // 10 -> 12 -> 15
    insertAtPosition(tail, head, 4, 22); // add at end

    // create loop: tail points to second node
    tail->next = head->next;

    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    // detect loop
    if(floydDetectLoop(head) != NULL)
        cout << "Cycle is present " << endl;
    else
        cout << "no cycle" << endl;

    // get loop starting node
    Node* loop = getStartingNode(head);
    cout << "loop starts at " 
         << loop->data << endl;

    // remove loop and print list
    removeLoop(head);
    print(head);

    return 0;
}
