void QueueStack :: push(int x)
{
       // queue<int> q1,q1;
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> swap = q1;
        q1 = q2;
        q2 = swap;
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
         
        //return q1.front();     
        int ans;
        if(q1.empty()) 
           ans=-1;
        else{
            ans=q1.front();
            q1.pop();
        }
        return ans;
}
