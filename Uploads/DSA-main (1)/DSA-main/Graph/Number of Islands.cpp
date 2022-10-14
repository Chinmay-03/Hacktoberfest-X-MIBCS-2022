/*int island(int i,int j,vector<vector<char>>& grid,int& count)
    {
       //if it is within bound
       if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size())
           return 0;
           
        if(grid[i][j]=='0')  //useless neighbour
            return 0;
            
        grid[i][j]='0';
        
        //call the neighbours and see if they are helpfull
        
        if(island(i-1,j,grid,count)==1) count++;  // above
        if(island(i+1,j,grid,count)==1) count++;  // below
        if(island(i,j-1,grid,count)==1) count++;  // left
        if(island(i,j+1,grid,count)==1) count++;  // right
        
        return 1;
    }*/
    void bfs(int row,int col,vector<vector<int>>& visited,vector<vector<char>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            // traverse through all neighbour to check it is one or zero
            for(int drow=-1;drow<=1;drow++)
            {
                for(int dcol=-1;dcol<=1;dcol++)
                {
                    int nrow=row+drow;
                    int ncol=col+dcol;
                    
                    if(nrow<n and nrow>=0 and ncol<m and ncol>=0 and !visited[nrow][ncol] and grid[nrow][ncol]=='1')
                    {
                        visited[nrow][ncol]=1;
                        q.push({nrow,ncol});
                        
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        /*int k=0;
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<m;j++)
            {
                int count=1;
                if(grid[i][j]=='1')
                {
                    island(i,j,grid,count);
                    k++;
                }
                
            }
        }
        */
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] and grid[i][j]=='1')
                {
                    count++;
                    bfs(i,j,visited,grid);
                }
            }
        }
        
        
        
        return count;
        
    }
