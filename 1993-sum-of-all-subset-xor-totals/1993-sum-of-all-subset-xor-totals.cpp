class Solution {
public:
 int fsum=0;
    void solve(vector<int>&nums,int ind , vector<int>&ans,int sum,int n)
    {
        if(ind==n)
        {
            fsum+=sum;
            return;
        }
        sum=sum^nums[ind];
        solve(nums,ind+1,ans,sum,n);
        sum=sum^nums[ind];
        solve(nums,ind+1,ans,sum,n);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int>ans;

        solve(nums,0,ans,0,nums.size());
       
        return fsum;

    }
};