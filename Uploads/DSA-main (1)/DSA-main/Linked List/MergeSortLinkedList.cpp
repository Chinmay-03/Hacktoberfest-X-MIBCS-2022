void MergeSorting(Node** headRef)
    {
         Node* head = *headRef;
         Node* a;
         Node* b;
 
         /* Base case -- length 0 or 1 */
        if ((head == NULL) || (head->next == NULL)) 
        {
           return;
        }
 
        /* Split head into 'a' and 'b' sublists */
        FrontBackSplit(head, &a, &b);
 
        /* Recursively sort the sublists */
        MergeSorting(&a);
        MergeSorting(&b);
 
        /* answer = merge the two sorted lists together */
        *headRef = SortedMerge(a, b);
    }
    
    Node* SortedMerge(Node* a, Node* b)
    {
        Node* result = NULL;
 
        /* Base cases */
       if (a == NULL)
         return (b);
       else if (b == NULL)
         return (a);
 
       /* Pick either a or b, and recur */
       if (a->data <= b->data) 
       {
          result = a;
          result->next = SortedMerge(a->next, b);
       }
       else 
       {
         result = b;
         result->next = SortedMerge(a, b->next);
       }
       return (result);
    }
    
    void FrontBackSplit(Node* source,Node** frontRef, Node** backRef)
    {
      Node* fast;
      Node* slow;
      slow = source;
      fast = source->next;
 
      /* Advance 'fast' two nodes, and advance 'slow' one node */
      while (fast != NULL) 
      {
        fast = fast->next;
        if (fast != NULL) 
        {
            slow = slow->next;
            fast = fast->next;
        }
      }
 
      /* 'slow' is before the midpoint in the list, so split it in two
      at that point. */
      *frontRef = source;
      *backRef = slow->next;
      slow->next = NULL;
    }
    
    Node* mergeSort(Node* head) 
    {
        MergSorting(&head);
        return head;
    }
