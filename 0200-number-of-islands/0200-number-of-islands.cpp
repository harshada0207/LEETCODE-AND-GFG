class Solution {
public:
    void bfs(int i,int j, vector<vector<int>>&vis,vector<vector<char>>& grid)
    {
        vis[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
       // cout<<i<<" "<<j;
        
       
            for(int drow=-1;drow<=1;drow++)
            {
                for(int dcol=-1;dcol<=1;dcol++)
                {
                    if(drow==-1 && dcol==1 || drow==1 && dcol==1 || drow==1 && dcol==-1 || drow==-1 && dcol==-1)
                    {
                        continue;
                    }
                    int nrow=i+drow;
                    int ncol=j+dcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1')
                    {
                        bfs(nrow,ncol,vis,grid);
                    }
                }
            }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int c=0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if( grid[row][col]=='1' && !vis[row][col])
                {
                    c++;
                    bfs(row,col,vis,grid);
                  
                }
            }
        }
        return c;

        
    }
};