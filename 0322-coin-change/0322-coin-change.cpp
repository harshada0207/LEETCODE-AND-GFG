class Solution {
public:
    int coinscount(int ind,vector<int>& coins, int amount, vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            if(amount%coins[ind]==0)
            {
                return (amount/coins[ind]);
            }
            return 1e9;
        }
        if(dp[ind][amount]!=-1)
        {
            return dp[ind][amount];
        }
        int not_take=coinscount(ind-1,coins,amount,dp);
        int take =INT_MAX;
        if(coins[ind]<=amount)
        {
            take=1+coinscount(ind,coins,amount-coins[ind],dp);
        }
        return dp[ind][amount]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       int ans =  coinscount(n-1,coins,amount,dp);
        return ans==1e9?-1:ans;
        
    }
};