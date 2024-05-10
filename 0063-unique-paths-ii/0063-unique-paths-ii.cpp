class Solution {
public:
    // int solve(vector<vector<int>>& obstacleGrid,int i,int j)
    // {
    //     if(i==0&&j==0)
    //     {
    //         return 1;
    //     }
    //     if(i<0 ||j<0)
    //     {
    //         return 0;
    //     }
    //     if(obstacleGrid[i][j]==1)
    //     {
    //         return 0;
    //     }
    //     if(i!=0 &&j==0)
    //     {
    //         return solve(obstacleGrid,i-1,j);
    //     }
    //      if(i==0 &&j!=0)
    //     {
    //         return solve(obstacleGrid,i,j-1);
    //     }
    //     return solve(obstacleGrid,i-1,j)+solve(obstacleGrid,i,j-1);
    // }
   int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();

    // Create dp array and initialize it with zeros
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Initialize dp[0][0] based on whether there's an obstacle at the starting position
    dp[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

    // Initialize the first column based on whether there are obstacles
    for (int i = 1; i < n; ++i) {
        dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1) ? 1 : 0;
    }

    // Initialize the first row based on whether there are obstacles
    for (int j = 1; j < m; ++j) {
        dp[0][j] = (obstacleGrid[0][j] == 0 && dp[0][j - 1] == 1) ? 1 : 0;
    }

    // Fill in the rest of the dp array
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (obstacleGrid[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // Return the number of unique paths to the bottom-right cell
    return dp[n - 1][m - 1];
}

};