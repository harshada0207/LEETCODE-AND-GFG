

class Solution {
public:
    // int solve(int ind, int n, vector<int> prices, vector<vector<vector<int>>>&dp, int buy, int counter) {
    //     if (ind == n || counter == 0) {
    //         return 0;
    //     }
    //     if (dp[ind][buy][counter] != -1) {
    //         return dp[ind][buy][counter];
    //     }
    //     if (buy) {
    //         int profit1 = -prices[ind] + solve(ind + 1, n, prices, dp, 0, counter);
    //         int profit2 = solve(ind + 1, n, prices, dp, 1, counter);
    //         return dp[ind][buy][counter] = max(profit1, profit2);
    //     } else {
    //         int profit1 = prices[ind] + solve(ind + 1, n, prices, dp, 1, counter -1);
    //         int profit2 = solve(ind + 1, n, prices, dp, 0, counter);
    //         return dp[ind][buy][counter]= max(profit1, profit2);
    //     }
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,-1)));
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                dp[n][i][j]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<2;j++)
            {
                dp[i][j][0]=0;
            }
        }
         for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<2;buy++)
            {
                for(int counter=1;counter<3;counter++)
                    {    
                        if(buy==0)
                        {
                            int profit1=prices[ind]+dp[ind+1][1][counter-1];
                            int profit2=dp[ind+1][0][counter];
                            dp[ind][buy][counter]=max(profit1,profit2);
                        }
                        else
                        {
                                int profit1=0-prices[ind]+dp[ind+1][0][counter];
                                int profit2=dp[ind+1][1][counter];
                                dp[ind][buy][counter]=max(profit1,profit2);
                        }
                    }
            }
        }
        return dp[0][1][2];
    }
};