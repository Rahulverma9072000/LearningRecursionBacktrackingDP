#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, int d)
{

    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    // new node create
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{

    // insert at Start
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // inserting at Last Position
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    // creating a node for d
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node *&head)
{
    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free start ndoe
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void print(Node *head)
{
    // base case
    if (head == NULL)
    {
        return;
    }
    cout << (head->data) << " ";
    print(head->next);
}
void printKFromEnd(Node *head, int k)
{
    // base case
    if (head == NULL)
    {
        return;
    }
    // RecursionCall
    printKFromEnd(head->next, k);
    // Waapis
    k--;
    if (k == 0)
    {
        cout << head->data << endl;
    }
}
// Reverse a Linked list
Node *reverseLL(Node *head)
{
    // base case
    if (head == NULL or head->next == NULL)
        return head;
    Node *recAns = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return recAns;
}
Node *reverseIterative(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *forward;
    Node *temp = head;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
// Reverse Linked List in a group of k
Node *kReverse(Node *head, int k)
{
    // base case
    if (head == NULL)
    {
        return NULL;
    }
    // 1 case-> first group or k-> reverse
    Node *prev = NULL;
    Node *curr = head;
    Node *forward;
    int count = 0;
    while (curr != NULL and count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    // check next is null or not
    if (forward != NULL)
    {
        head->next = kReverse(forward, k);
    }
    return prev;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *root = new Node(3);
    head = tail = root;
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 5);
    print(head);
    cout << endl;
    head = reverseLL(head);
    print(head);
    return 0;
}