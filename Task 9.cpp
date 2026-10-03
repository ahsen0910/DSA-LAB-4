#include <iostream>
using namespace std;

struct Node {
    int ID;
    int Severity;
    Node *next;
    Node *prev;

    Node(int Id, int Sev) {
        ID = Id;
        Severity = Sev;
        next = NULL;
        prev = NULL;
    }
};

Node *GetNode(Node *Head, int Position) {

    Node *Curr = Head;

    for (int i = 0; i < Position; i++)
        Curr = Curr->next;

    return Curr;
}

void ShellSort(Node *Head, int Count) {

    for (int Gap = Count / 2; Gap > 0; Gap /= 2) {

        for (int i = Gap; i < Count; i++) {

            Node *Current = GetNode(Head, i);
            int CurrentID = Current->ID;
            int CurrentSeverity = Current->Severity;

            int j = i;

            while (j >= Gap) {

                Node *Previous = GetNode(Head, j - Gap);

                if (Previous->Severity <= CurrentSeverity)
                    break;

                Node *Target = GetNode(Head, j);

                Target->ID = Previous->ID;
                Target->Severity = Previous->Severity;

                j -= Gap;
            }

            Node *Target = GetNode(Head, j);

            Target->ID = CurrentID;
            Target->Severity = CurrentSeverity;
        }
    }
}




