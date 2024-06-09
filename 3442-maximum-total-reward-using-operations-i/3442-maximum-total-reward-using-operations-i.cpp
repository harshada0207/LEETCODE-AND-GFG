class Solution {
public:
    int solve(vector<int>& rewardValues,int n,int ind,int sum,vector<vector<int>>&dp)
    {
        if(ind==n)
        {
            return sum;
        }
        if(dp[ind][sum]!=-1)
        {
            return dp[ind][sum];
        }
        int mark=INT_MIN;
        if(sum<rewardValues[ind])
        {
             
              mark=solve(rewardValues,n,ind+1,sum+rewardValues[ind],dp);
        }
        int not_mark=solve(rewardValues,n,ind+1,sum,dp);

        return dp[ind][sum]=max(mark,not_mark);
    }
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());
        int n=rewardValues.size();
        vector<vector<int>>dp(n,vector<int>(4000,-1));
        return solve(rewardValues,n,0,0,dp);
        
    }
};