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

int CountTriplets(Node *Head, int X) {

    if (Head == NULL)
        return 0;

    Node *Tail = Head;

    while (Tail->next != NULL)
        Tail = Tail->next;

    int Count = 0;

    Node *First = Head;

    while (First != NULL) {

        Node *Second = First->next;
        Node *Third = Tail;

        while (Second != NULL &&
               Third != NULL &&
               Second != Third &&
               Second->prev != Third) {

            int Sum = First->data + Second->data + Third->data;

            if (Sum == X) {
                Count++;
                Second = Second->next;
                Third = Third->prev;
            }
            else if (Sum < X) {
                Second = Second->next;
            }
            else {
                Third = Third->prev;
            }
        }

        First = First->next;
    }

    return Count;
}
