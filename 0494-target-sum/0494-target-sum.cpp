class Solution {
    private:
    int solve(vector<int>& nums, int target,int ind,int sum)
    {   
       if(ind==0)
       {
           if(sum+nums[0]==target && sum-nums[0]==target)
          {
            return 2;
           }
           else if(sum+nums[0]==target || sum-nums[0]==target)
           {
            return 1;
           }
           
         return 0;
       }
      
       int left = solve(nums,target,ind-1,sum-nums[ind]);
       int right = solve(nums,target,ind-1,sum+nums[ind]);

       return left+right;
      
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        int ans = solve(nums,target,n-1,sum);
        return ans;
    }
};
