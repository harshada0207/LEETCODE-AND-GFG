class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,-1)));
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<=k;j++)
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
                for(int counter=1;counter<=k;counter++)
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
        return dp[0][1][k];
    

    }
};