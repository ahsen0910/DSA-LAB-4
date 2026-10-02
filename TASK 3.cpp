bool IsPalindrome(Node *Head) {

    Node *Slow = Head;
    Node *Fast = Head;

    while (Fast != NULL && Fast->next != NULL) {
        Slow = Slow->next;
        Fast = Fast->next->next;
    }

    Node *Pre = NULL;
    Node *Curr = Slow;
    Node *Next = NULL;

    while (Curr != NULL) {
        Next = Curr->next;
        Curr->next = Pre;
        Pre = Curr;
        Curr = Next;
    }

    Node *First = Head;
    Node *Second = Pre;

    while (Second != NULL) {
        if (First->data != Second->data)
            return false;

        First = First->next;
        Second = Second->next;
    }

    return true;
}
