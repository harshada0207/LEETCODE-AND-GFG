class Solution {
public:
   int solve(int i,int j,vector<vector<int>>&dp)
    {
        if(i==0 || j==0)
        {
            return 0;
        }
        if(i==1 && j==1)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
     
         if(i>1 &&j==1)
        {
            return dp[i][j]=solve(i-1,j,dp);
        }
         if(i==1 &&j>1)
        {
            return dp[i][j]=solve(i,j-1,dp);
        }
        
        return dp[i][j]=solve(i-1,j,dp)+solve(i,j-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve (m,n,dp);
    }
};