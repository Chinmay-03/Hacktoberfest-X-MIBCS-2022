 Node* reverse(Node* temp)
    {
        if(!temp or !temp->next) 
        {
            return temp;
        }
        Node*current=temp;
        Node* previous=NULL;
        Node* next=NULL;
        
        while(current!=NULL)
        {
            next=current->next;
            current->next=previous;
            previous=current;
            current=next;
            
        }
        temp=previous;
        
        return temp;
    }
    bool isPalindrome(Node *head)
    {
        
        
        if(!head or !head->next) 
        {
            return true;
        }
        
        Node *fast = head, *slow = head, *prevElement = NULL;
        
        while(fast and fast->next) 
        {
            prevElement = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prevElement->next = NULL;
        
        Node *halfHead = reverseList(slow);
        Node *p = head, *q = halfHead;
        
        while(p and q) 
        {
            if(p->data != q->data) 
            {
                return false;
            }
            p = p->next;
            q = q->next;
        }
        return true;
    }
