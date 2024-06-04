class Solution {
public:
    int solve(vector<int>& nums, int target,int ind)
    {
        if(ind<0)
        {
            if(target==0)
            {
                return 1;
            }
            return 0;
        }
        int left=solve(nums,target+nums[ind],ind-1);
        int right=solve(nums,target-nums[ind],ind-1);
        return left+right;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(nums,target,n-1);
    }
};