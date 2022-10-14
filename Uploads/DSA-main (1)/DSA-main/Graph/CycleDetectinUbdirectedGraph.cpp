bool ifcheckCycle(int s,vector<int> adj[], vector<int>& visited)
    {  
        queue<pair<int,int>> q;
        
        q.push({s,-1});
        visited[s]=1;
        
        while(!q.empty())
        {
            int node=q.front().first;
            int prev=q.front().second;
            q.pop();
            
            for(auto it:adj[node])
            {
                if(!visited[it])
                {
                    q.push({it,node});
                    visited[it]=1;
                    
                }
                else if(prev != it)
                {
                   return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<int> visited(V,0);
        
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                if(ifcheckCycle(i,adj,visited))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
