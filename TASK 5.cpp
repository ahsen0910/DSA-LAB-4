Node *Intersection(Node *Head1, Node *Head2) {

    int Length1 = 0;
    int Length2 = 0;

    Node *Curr1 = Head1;
    Node *Curr2 = Head2;

    while (Curr1 != NULL) {
        Length1++;
        Curr1 = Curr1->next;
    }

    while (Curr2 != NULL) {
        Length2++;
        Curr2 = Curr2->next;
    }

    Curr1 = Head1;
    Curr2 = Head2;

    if (Length1 > Length2) {
        for (int i = 0; i < Length1 - Length2; i++)
            Curr1 = Curr1->next;
    }
    else {
        for (int i = 0; i < Length2 - Length1; i++)
            Curr2 = Curr2->next;
    }

    while (Curr1 != Curr2) {
        Curr1 = Curr1->next;
        Curr2 = Curr2->next;
    }

    return Curr1;
}
