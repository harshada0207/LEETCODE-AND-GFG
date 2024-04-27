class Solution {
public:
    int count=0;
    void solve(vector<int>& nums, int target,int sum,int ind)
    {
        if(ind==nums.size())
        {
            if(sum==target)
            {
                  count++;

            }
            return;
        }
        solve(nums,target,sum+nums[ind],ind+1);
        solve(nums,target,sum-nums[ind],ind+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int ind=0;
        solve(nums,target,sum,ind);
        return count;
    }
};