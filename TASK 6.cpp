#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int Data) {
        data = Data;
        next = NULL;
    }
};

Node *OddEven(Node *Head) {

    Node *OddHead = NULL;
    Node *OddTail = NULL;
    Node *EvenHead = NULL;
    Node *EvenTail = NULL;

    Node *Curr = Head;

    while (Curr != NULL) {

        if (Curr->data % 2 != 0) {

            if (OddHead == NULL)
                OddHead = OddTail = Curr;
            else {
                OddTail->next = Curr;
                OddTail = Curr;
            }
        }
        else {

            if (EvenHead == NULL)
                EvenHead = EvenTail = Curr;
            else {
                EvenTail->next = Curr;
                EvenTail = Curr;
            }
        }

        Curr = Curr->next;
    }

    if (OddHead == NULL)
        return EvenHead;

    OddTail->next = EvenHead;

    if (EvenTail != NULL)
        EvenTail->next = NULL;

    return OddHead;
}
