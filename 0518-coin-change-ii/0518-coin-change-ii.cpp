class Solution {
public:
    int solve(vector<int>& coins,int amount,int ind, vector<vector<int>>&dp)
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
        int take=0;
        if(coins[ind]<=amount)
        {
            take=solve(coins,amount-coins[ind],ind,dp);
        }
        int nottake=solve(coins,amount,ind-1,dp);
        return dp[ind][amount]= take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(coins,amount,n-1,dp);
    }
};