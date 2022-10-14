 bool iscycleDFS(int sv,int prev,vector<int>& visited,vector<int> adj[])
    {
        visited[sv]=1;
        for(auto it:adj[sv])
        {
            if(!visited[it])
            {
                if(iscycleDFS(it,sv,visited,adj))
                     return true;
            }
            else if(it != prev)
            {
                return false;
            }
        }
        
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) 
    {
        vector<int> visited(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(iscycleDFS(i,-1,visited,adj))
                {
                    return true;
                }
            }
        }
        
        return false;
        
        
    }
