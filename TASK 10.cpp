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

Node *FindAndRemoveLoop(Node *Head) {

    Node *Slow = Head;
    Node *Fast = Head;

    while (Fast != NULL && Fast->next != NULL) {

        Slow = Slow->next;
        Fast = Fast->next->next;

        if (Slow == Fast)
            break;
    }

    // No loop
    if (Fast == NULL || Fast->next == NULL)
        return NULL;

    Node *Current = Head;
    Node *Pre = NULL;

    while (Current != Fast) {
        Pre = Current;
        Current = Current->next;
    }
    Slow = Head;

    while (Slow != Fast) {
        Slow = Slow->next;
        Fast = Fast->next;
        Pre = Pre->next;
    }

    Pre->next = NULL;

    return Slow;
}


