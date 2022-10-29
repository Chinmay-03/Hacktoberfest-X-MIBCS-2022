# include <iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    // constructor
    Node ( int data ) {
        this -> data = data;
        this -> next = NULL;
    }

    // ~Node () {
    //     int val = this->data;
    //     if ( this -> next != NULL ) {
    //         delete next;
    //         this -> next = NULL;
    //     }
    //     cout << "memory is free for node with data " << val << endl;
    // }


};

void insertAtHead( Node * &head , int d ) {

    // new node creation
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail ( Node* &tail, int d ) {

    // new node creation
    Node* temp = new Node(d);

    tail -> next = temp;

    tail = tail -> next;
}

void insertAtPosition ( Node* &head, Node* &tail, int pos, int d ) {

    if (pos == 1) {
        insertAtHead(head,d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while ( cnt < pos-1 ) {
        temp = temp -> next;
        cnt++;
    }

    if ( temp -> next == NULL ) {
        insertAtTail(tail,d);
        return;
    }
    Node* nodeToInsert = new Node(d);



    nodeToInsert -> next = temp ->next;
    temp -> next = nodeToInsert;

}

void print ( Node* &head ){

    Node* temp = head;

    while ( temp != NULL ) {
        cout << temp -> data <<" ";
        temp = temp -> next;
    }

    cout << endl;
}

void deleteNode(Node* head, int pos ){

    if ( pos==1 ) {
        Node* temp = head;
        head = head -> next;
        delete temp;
    }
}


int main () {

    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    print(head);

    insertAtTail(tail,12);

    print(head);

    insertAtHead(head,15);

    print(head);

    insertAtPosition(head,tail,4,22);

    print(head);

    cout << tail -> data << endl;
    cout << head -> data << endl;

    deleteNode(head,1);

    print(head);





    return 0;
}