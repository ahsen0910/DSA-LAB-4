#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int Data) {
        data = Data;
        next = NULL;
        prev = NULL;
    }
};

Node *RemoveDuplicates(Node *Head) {

    Node *Curr = Head;

    while (Curr != NULL && Curr->next != NULL) {

        if (Curr->data == Curr->next->data) {

            Node *Duplicate = Curr->next;

            Curr->next = Duplicate->next;

            if (Duplicate->next != NULL)
                Duplicate->next->prev = Curr;

            delete Duplicate;
        }
        else {
            Curr = Curr->next;
        }
    }

    return Head;
}

