class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j, vector<vector<int>>&dp)
    {
        if(i==0 && j==0)
        {
            return grid[0][0];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int up=INT_MAX;
        int left=INT_MAX;
        if(i>0)
        { up=grid[i][j]+solve(grid,i-1,j,dp);}
        if(j>0)
       {  left=grid[i][j]+solve(grid,i,j-1,dp);}
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
            return solve(grid,n-1,m-1,dp);
    }
};