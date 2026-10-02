Node *Merge(Node *Head1, Node *Head2) {

    if (Head1 == NULL)
        return Head2;

    if (Head2 == NULL)
        return Head1;

    Node *Head = NULL;
    Node *Tail = NULL;

    while (Head1 != NULL && Head2 != NULL) {

        if (Head1->data <= Head2->data) {

            if (Head == NULL)
                Head = Tail = Head1;
            else {
                Tail->next = Head1;
                Tail = Head1;
            }

            Head1 = Head1->next;
        }
        else {

            if (Head == NULL)
                Head = Tail = Head2;
            else {
                Tail->next = Head2;
                Tail = Head2;
            }

            Head2 = Head2->next;
        }
    }

    if (Head1 != NULL)
        Tail->next = Head1;

    if (Head2 != NULL)
        Tail->next = Head2;

    return Head;
}
