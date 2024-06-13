class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>& grid,int&count)
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        count+=1;
        int delrow[]={0,-1,0,1};
        int delcol[]={-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int nrow=delrow[k]+row;
            int ncol=delcol[k]+col;
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            {
                  dfs(nrow,ncol,vis,grid,count);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    int count=0;
                    dfs(i,j,vis,grid,count);
                    ans=max(ans,count);
                }
            }
        }
        return ans;
        
    }
};