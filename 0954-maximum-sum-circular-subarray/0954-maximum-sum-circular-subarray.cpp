class Solution {
public:
    int kadane(vector<int>& nums)
    {
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            maxi=max(sum,maxi);
            if(sum<0)
            {
                sum=0;
            }
        }
        return maxi;
    }
    int revkadane(vector<int>& nums)
    {
        int sum=0;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(sum>0)
            {
                sum=nums[i];
            }
            else
            {
                sum+=nums[i];
            }
            
            mini=min(sum,mini);
           
        }
        return mini;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_sum=kadane(nums);
        int min_sum=revkadane(nums);
        int tsum=accumulate(nums.begin(),nums.end(),0);
        int cir_sum= tsum-min_sum;
        if(max_sum>0)
        {
            return max(max_sum,cir_sum);
        }
        return max_sum;

    }
};