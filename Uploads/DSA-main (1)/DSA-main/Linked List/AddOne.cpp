// GeeksforGeeks

Node* reverse(Node *head)
    {
        Node* current=head,*previous=NULL,*next=head;
        while(current!=NULL)
        {
            next=current->next;
            current->next=previous;
            previous=current;
            current=next;
        }
        
        
        return previous;
    }
Node* addOne(Node *head) 
    {
        Node* new_head=reverse(head);
        Node* current=new_head,*previous=NULL,*current1=new_head;
        int carry=0;
        
        while(current!=NULL)
        {
            int sum=0;
            if(previous==NULL)
                sum=current->data+1;
            else
                sum=current->data+carry;
            
            carry=sum/10;
            current->data=sum%10;
            previous=current;
            current=current->next;
            
        }
        
        if(carry==1)
        {
            Node* newhead=new Node(carry);
            previous->next=newhead;
        }
        
        
        return reverse(current1);
        
    }
