class Solution {
public:
    bool solve(int n,vector<int>& nums,int k, vector<vector<int>>&dp)
    {
          if(k==0)
          {
            return true;
          }
          if(n==0)
          {
            return (nums[0]==k);
          }
          if(dp[n][k]!=-1)
          {
            return dp[n][k];
          }
          bool not_take=solve(n-1,nums,k,dp);
          bool take=false;
          if(nums[n]<=k)
          {
            take=solve(n-1,nums,k-nums[n],dp);
          }
          return dp[n][k]=(take||not_take);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)
        {
            return false;
        }
        int k=sum/2;
        vector<vector<int>>dp(nums.size(),vector<int>(k+1,-1));
        return solve(nums.size()-1,nums,k,dp);
        
    }
};