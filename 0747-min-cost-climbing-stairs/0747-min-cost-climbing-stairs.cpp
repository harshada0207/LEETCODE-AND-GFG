class Solution {
public:
    // int solve(int ind,vector<int>& cost,vector<int>&dp)
    // {
    //     if(ind==1 || ind==0)
    //     {
    //         return 0;
    //     }
       
    //     if(dp[ind]!=-1)
    //     {
    //         return dp[ind];
    //     }
        
    //     int one=cost[ind-1]+solve(ind-1,cost,dp);
    //     int two=cost[ind-2]+solve(ind-2,cost,dp);

    //     return dp[ind]=min(one,two);

    // }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=n;i++)
        {
              int one=cost[i-1]+dp[i-1];
              int two=cost[i-2]+dp[i-2];
              dp[i]=min(one,two);
        }
        return dp[n];
    }
};