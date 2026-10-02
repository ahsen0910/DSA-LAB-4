
Node *FindMiddle(Node * Head){

    Node * Slow = Head;
    Node *Fast = Head;

    while (Fast != NULL && Fast->next != NULL){
        
        Slow = Slow->next;
        Fast = Fast->next->next;

    }
    return Slow;

}
