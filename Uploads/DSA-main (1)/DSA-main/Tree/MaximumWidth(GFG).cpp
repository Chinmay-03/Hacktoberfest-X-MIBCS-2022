// just only given node
int getMaxWidth(Node* root) {

        
        queue<Node*> q;
        q.push(root);
       
        int maxwid=0;
        while(!q.empty())
        {
            
            if(!root)
               return 0;
           int n=q.size();
           
              
           for(int i=0;i<n;i++)
           {
                Node* node=q.front();
               q.pop();
              
               if(node->left)
                  q.push(node->left);
               if(node->right)
                  q.push(node->right);
           }
           
           maxwid=max(maxwid,n);
         
           
        }
        
        return maxwid;
    }
