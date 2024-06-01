class Solution {
public:
   
    int solve(vector<int>&nums,int ind,int prev_ind, vector<vector<int>>&dp)
    {
        if(ind==nums.size())
        {
            return 0;
        }
       if(dp[ind][prev_ind+1]!=-1)
       {
          return dp[ind][prev_ind+1];
       }
       int take= INT_MIN;
       if(prev_ind==-1 ||nums[ind]>nums[prev_ind])
       {
          take=1+solve(nums,ind+1,ind,dp);
       }
     
       int not_take=solve(nums,ind+1,prev_ind,dp);
       
       return dp[ind][prev_ind+1]= max(take,not_take);
        

       
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(nums,0,-1,dp);
        
        
    }
};