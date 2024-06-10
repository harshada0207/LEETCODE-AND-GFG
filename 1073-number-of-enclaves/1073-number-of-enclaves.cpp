class Solution {
public:
    
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid,int delrow[],int delcol[])
    {
        vis[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int k=0;k<4;k++)
        {
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            {
                dfs(nrow,ncol,vis,grid,delrow,delcol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delrow[]={0,-1,0,+1};
        int delcol[]={-1,0,1,0};
        for(int i=0;i<n;i++)
        {
            if(vis[i][0]==0 && grid[i][0]==1)
            {dfs(i,0,vis,grid,delrow,delcol);}
            
        }
        for(int j=0;j<m;j++)
            {
                 if(vis[0][j]==0 && grid[0][j]==1)
                 {dfs(0,j,vis,grid,delrow,delcol);}
            }
        for(int i=0;i<n;i++)
        {
            if(vis[i][m-1]==0 && grid[i][m-1]==1)
            {dfs(i,m-1,vis,grid,delrow,delcol);}
            
        }
        for(int j=0;j<m;j++)
            {
                 if(vis[n-1][j]==0 && grid[n-1][j]==1)
                 {dfs(n-1,j,vis,grid,delrow,delcol);}
            }
            int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    count++;
                }
            }
        }
        return count++;
    }
};