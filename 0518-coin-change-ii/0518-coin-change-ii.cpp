class Solution {
public:
     int coinscount(int ind,vector<int>& coins, int amount, vector<vector<int>>&dp)
    {
        if(ind<0)
        {
            if(amount==0)
            {
                return 1;
            }
            return 0;
        }
        if(dp[ind][amount]!=-1)
        {
            return dp[ind][amount];
        }
        int not_take=coinscount(ind-1,coins,amount,dp);
        int take =0;
        if(coins[ind]<=amount)
        {
            take=coinscount(ind,coins,amount-coins[ind],dp);
        }
        return dp[ind][amount]=take+not_take;
    }
    int change(int amount, vector<int>& coins) {
         int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       int ans =  coinscount(n-1,coins,amount,dp);
        return ans;

        
    }
};