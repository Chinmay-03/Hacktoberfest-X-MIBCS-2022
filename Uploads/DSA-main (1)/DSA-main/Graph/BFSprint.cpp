
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
          vector<int> v;
          vector<int> visited(V,0);
          queue<int> q;
          q.push(0);
          visited[0]=1;
          
          while(!q.empty())
          {
              int node=q.front();
              v.push_back(node);
              q.pop();
              
              for(auto it:adj[node])
              {
                  if(!visited[it])
                  {
                      q.push(it);
                      visited[it]=1;
                  }
              }
          }
          
          return v;
          
    }
