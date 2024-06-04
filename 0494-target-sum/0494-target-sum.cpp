class Solution {
public:
    int solve(vector<int>& nums, int target,int ind,vector<vector<int>>&dp)
    {
        
        if(ind<0)
        {
            if(target==0)
            {
                return 1;
            }
            return 0;
        }
        if(dp[ind][target+2000]!=-1)
        {
            return dp[ind][target+2000];
        }
        int left=solve(nums,target+nums[ind],ind-1,dp);
        int right=solve(nums,target-nums[ind],ind-1,dp);
        return dp[ind][target+2000]=left+right;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(4001,-1));
        return solve(nums,target,n-1,dp);
    }
};