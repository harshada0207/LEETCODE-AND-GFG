class Solution {
public:

    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&board,int delrow[],int delcol[])
    {
        vis[i][j]=1;
        int n=board.size();
        int m=board[0].size();
        for(int k=0;k<4;k++)
        {
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O')
            {
                dfs(nrow,ncol,vis,board,delrow,delcol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delrow[]={0,-1,0,+1};
        int delcol[]={-1,0,1,0};
        for(int i=0;i<n;i++)
        {
            if(vis[i][0]==0 && board[i][0]=='O')
            {dfs(i,0,vis,board,delrow,delcol);}
            
        }
        for(int j=0;j<m;j++)
            {
                 if(vis[0][j]==0 && board[0][j]=='O')
                 {dfs(0,j,vis,board,delrow,delcol);}
            }
        for(int i=0;i<n;i++)
        {
            if(vis[i][m-1]==0 && board[i][m-1]=='O')
            {dfs(i,m-1,vis,board,delrow,delcol);}
            
        }
        for(int j=0;j<m;j++)
            {
                 if(vis[n-1][j]==0 && board[n-1][j]=='O')
                 {dfs(n-1,j,vis,board,delrow,delcol);}
            }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && vis[i][j]==0)
                {
                    board[i][j]='X';
                }
            }
        }
    }
};