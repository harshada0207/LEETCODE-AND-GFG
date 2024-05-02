class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][n]=0;
        }
        for(int i=0;i<=n;i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++)
        {
             for(int j=n-1;j>=0;j--)
             {
                if(s[i-1]==s[j])
                {
                    dp[i][j]=1+dp[i-1][j+1];
                }
                else
                {
                    dp[i][j]=max(dp[i][j+1],dp[i-1][j]);
                }
             }

        }

        return dp[n][0];
        
    }
};