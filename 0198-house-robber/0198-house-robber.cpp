class Solution {
public:
int f(int ind ,vector<int>& nums,vector<int>&dp)
{
    if(ind==0)
    {
        return dp[ind]=nums[ind];
    }
    if(ind<0)
    {
        return 0;
    }
    if(dp[ind]!=-1)
    {
        return dp[ind];
    }
    
    
    int  pick=nums[ind]+f(ind-2,nums,dp);
    
    int not_pick=0+f(ind-1,nums,dp);
    return dp[ind]=max(pick,not_pick);
}
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        f(nums.size()-1,nums,dp); 
        return dp[nums.size()-1];
    }
};