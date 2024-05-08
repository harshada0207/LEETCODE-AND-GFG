class Solution {
public:
    // int solve(int ind,int n,vector<int>prices, vector<vector<int>>&dp,int buy)
    // {
    //     if(ind==n)
    //     {
    //         return 0;
    //     }
    //     if(dp[ind][buy]!=-1)
    //     {
    //         return dp[ind][buy];
    //     }
    //     if(buy)
    //     { 
    //         int profit1=0-prices[ind]+solve(ind+1,n,prices,dp,0);
    //         int profit2=0+solve(ind+1,n,prices,dp,1);
    //         return dp[ind][buy]=max(profit1,profit2);

    //     }
    //     else
    //     {
    //         int profit1=prices[ind]+solve(ind+1,n,prices,dp,1);
    //         int profit2=solve(ind+1,n,prices,dp,0);
    //         return dp[ind][buy]=max(profit1,profit2);
    //     }

   // }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        dp[n][0]=0;
        dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<2;buy++)
            {
                if(buy==0)
                {
                    int profit1=prices[ind]+dp[ind+1][1];
                    int profit2=dp[ind+1][0];
                    dp[ind][buy]=max(profit1,profit2);
                }
                else
                {
                        int profit1=0-prices[ind]+dp[ind+1][0];
                        int profit2=dp[ind+1][1];
                        dp[ind][buy]=max(profit1,profit2);
                }
            }
        }
        return (dp[0][1]);
        
    }
};