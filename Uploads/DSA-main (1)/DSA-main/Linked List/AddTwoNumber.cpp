//

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* link1=l1;
        ListNode* link2=l2;
        int n1=0,n2=0;
        vector<int> v1,v2;
        while(link1 !=NULL)
        {
            n1++;
            v1.push_back(link1->val);
            link1=link1->next;
        }
        
        while(link2 !=NULL)
        {
            n2++;
            v2.push_back(link2->val);
            link2=link2->next;
        }
        
       long long int k1=0,k2=0;
        for(int i=0;i<n1;i++)
        {
            k1=k1+v1[i]*pow(10,n1-i-1);
        }
        
        for(int i=0;i<n2;i++)
        {
            k2=k2+v2[i]*pow(10,n2-i-1);
        }
        
       long long int k=k1+k2;
        
        ListNode* f=NULL;
        if(k==0)
        {
            ListNode *temp = new ListNode(0);
            temp->next = f;
            f = temp;
            return f;
        }
         while(k>0)
         {
            ListNode *temp = new ListNode(k%10);
            temp->next = f;
            f = temp;
            k = k/10;
         }
        
        
        
        return f;
    }
