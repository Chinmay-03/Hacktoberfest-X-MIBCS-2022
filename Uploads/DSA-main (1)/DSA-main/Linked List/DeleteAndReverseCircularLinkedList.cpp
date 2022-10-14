void deleteNode(struct Node **head, int key)
{
  struct Node *p=*head;
  struct Node *temp;
  struct Node *q=NULL;
   
   while(p->next!=*head)
   {
       if(p->data==key)
       {
           temp=p;
           q->next=p->next;
           free(temp);
           return;
       }
       else
       {
           q=p;
           p=p->next;
       }
   }
}

/* Function to reverse the linked list */
 void reverse(struct Node** head_ref)
{
    
   /*  if (*head_ref == NULL)
    {
        return;
    }
    struct Node* current=*head_ref;
    struct Node* next=current->next;
    struct Node* previous=NULL;
    
    while(current!=*head_ref)
    {
        next=current->next;
        current->next=previous;
        previous=current;
        current=next;
    }
    current->next=previous;
    *head_ref=previous;*/
  
   struct Node *p=*head_ref;
   struct Node *temp=NULL; 
   struct Node *nex;
   
   while(p->next!=*head_ref)
   {
       nex=p->next;
       p->next=temp;
       temp=p;
       p=nex;
   }
   nex=p->next;
   p->next=temp;
   temp=p;
   p=nex;
   p->next=temp;
   *head_ref=temp;


    

}
