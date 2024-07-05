class Solution {
public:
    int solve(int col ,int row,vector<vector<int>>& matrix,int m,vector<vector<int>>&dp)
    {
       
        if(col<0 || col>=m)
        {
            return 1e9;
        }
        if(row==0)
        {
          return matrix[0][col];
        }
        if(dp[row][col]!=-1)
        {
            return dp[row][col];
        }
        int one=matrix[row][col]+solve(col,row-1,matrix,m,dp);
        int two=matrix[row][col]+solve(col-1,row-1,matrix,m,dp);
        int three=matrix[row][col]+solve(col+1,row-1,matrix,m,dp);

        return dp[row][col]=min(one,min(two,three));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mini=INT_MAX;
        vector<int>prev(m,0);vector<int>curr(m,0);
         for(int i=0;i<m;i++)
         {
            prev[i]=matrix[0][i];
         }
        for(int row=1;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                  int one=matrix[row][col]+prev[col];
                  int two=1e9;
                  int three=1e9;
                  if(col-1>=0)
                    {two=matrix[row][col]+prev[col-1];}
                  if(col+1<m)
                    {three=matrix[row][col]+prev[col+1];}
                  curr[col]=min(one,(min(two,three)));
            }
            prev=curr;
          
        }
        for(int i=0;i<m;i++)
        {
            mini=min(prev[i],mini);
        }
        return mini;
    }
};