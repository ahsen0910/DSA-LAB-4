
Node *Reverse(Node* Head){

    Node * Curr = Head;
    Node *Pre = NULL, * Next = NULL;

    while(Curr != NULL){
        Next = Curr->next;
        Curr->next = Pre;
        Pre = Curr;
        Curr = Next;
    }

    return Pre;
}
