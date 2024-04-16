class Solution {
public:
int stairs(int n,vector<int>&dp)
    {
        if(n<=2)
        {
            return n;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return dp[n]=stairs(n-1,dp)+stairs(n-2,dp);
    }
        
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int ans=stairs(n,dp);
        return ans;
       
        
    }
};