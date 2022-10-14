void addNode(Node *head, int pos, int data)
{
   Node* temp  = new Node(data);
   Node* loop = head;
   Node* pre = NULL;
   while(pos>=0)
   {
       pre=loop;
       loop=loop->next;
       pos--;
   }
   if(pre->next==NULL)
   {
       pre->next=temp;
       temp->next=NULL;
       temp->prev=pre;
   }
   else
   {
       temp->next=loop;
       temp->prev=pre;
       loop->prev=temp;
       pre->next=temp;   
   }
   
   
}
