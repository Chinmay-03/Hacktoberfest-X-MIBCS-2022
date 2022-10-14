 int orangesRotting(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m));
        
        queue<pair<pair<int,int>,int>> q;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    visited[i][j]=2;
                    
                }
                else
                    visited[i][j]=0;
            }
        }
        
        int Time=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int tim=q.front().second;
            Time=max(Time,tim);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and visited[nrow][ncol]!=2 and grid[nrow][ncol]==1)
                {
                     visited[nrow][ncol]=2;
                    q.push({{nrow,ncol},tim+1});
                }
            }
            
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]!=2 and grid[i][j]==1)
                {
                    return -1;
                }
                
            }
        }
        
        return Time;
    }
