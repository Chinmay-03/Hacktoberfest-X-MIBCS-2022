Node* reverseDLL(Node * head)
{
    Node* previous=NULL;
    Node* current=head;
    
    while(current!=NULL)
    {
        previous=current->prev;
        current->prev=current->next;
        current->next= previous;
        current=current->prev;
    }
    if(previous!=NULL)
    {
        head=previous->prev;
    }
    
    
    return head;
}
