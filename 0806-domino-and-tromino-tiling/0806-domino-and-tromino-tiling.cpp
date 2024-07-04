class Solution {
public:
    int numTilings(int n) {
        const int MOD=1e9+7;
        vector<int>dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        if(n>=2)
        {dp[2]=2;}
        for(int i=3;i<=n;i++)
        {
            dp[i]=((dp[i-1]*2)%(MOD)+dp[i-3])%(MOD);
        }
        return dp[n];
    }
};