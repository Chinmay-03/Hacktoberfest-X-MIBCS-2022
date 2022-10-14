****************************-----------DFS----------*********************************

void dfs(int row,int col,int color,vector<vector<int>>& image,int k)
    {
        int n=image.size(),m=image[0].size();
        
        if(row<0 || col<0 ||row>=n || col>=m)
          return;
          
        if(image[row][col]==color)
          return;
        
        if(image[row][col]!=k)
           return;
        
        image[row][col]=color;
        
        dfs(row+1,col,color,image,k);
        dfs(row-1,col,color,image,k);
        dfs(row,col+1,color,image,k);
        dfs(row,col-1,color,image,k);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int k=image[sr][sc];
        dfs(sr,sc,newColor,image,k);
        
        return image;
        
    }

******************************----------BFS------------********************************


void bfs(int sr,int sc,int color,vector<vector<int>>& visited,vector<vector<int>>& image,int source)
    {
        visited[sr][sc]=1;
        int n=image.size();
        int m=image[0].size();
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            if(row-1>=0 and image[row][col]==image[row-1][col] and visited[row-1][col]==0)
            {
                visited[row-1][col]=1;
                q.push({row-1,col});
            }
            
            if(row+1<n and image[row][col]==image[row+1][col] and visited[row+1][col]==0)
            {
                visited[row+1][col]=1;
                q.push({row+1,col});
            }
                                                          
            if(col-1>=0 and image[row][col]==image[row][col-1] and visited[row][col-1]==0)
            {
                visited[row][col-1]=1;
                q.push({row,col-1});
            }
                                                          
            if(col+1<m and image[row][col]==image[row][col+1] and visited[row][col+1]==0)
            {
                visited[row][col+1]=1;
                q.push({row,col+1});
            }
            image[row][col]=color;
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int n=image.size();
        int m=image[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        int source=image[sr][sc];
        bfs(sr,sc,color,visited,image,source);
        
        return image;
        
    }
