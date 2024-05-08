class Solution {
public:
   int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        dp[n][0]=0;
        dp[n][1]=0;
        dp[n][2]=0;
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<3;buy++)
            {
                if(buy==0)
                {
                    int profit1=prices[ind]+dp[ind+1][1];
                    int profit2=dp[ind+1][0];
                    dp[ind][buy]=max(profit1,profit2);
                }
                else if(buy==1)
                {
                    int profit1=dp[ind+1][2];
                    
                    dp[ind][buy]=profit1;
                }
                else
                {
                        int profit1=0-prices[ind]+dp[ind+1][0];
                        int profit2=dp[ind+1][2];
                        dp[ind][buy]=max(profit1,profit2);
                }
            }
        }
        return (dp[0][2]);
        
    }
};