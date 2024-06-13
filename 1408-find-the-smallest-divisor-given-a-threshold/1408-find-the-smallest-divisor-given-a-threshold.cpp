class Solution {
public:
    bool func(int mid,vector<int>& nums, int threshold)
    {
        double sum=0;
        for(int i=0;i<nums.size();i++)
        {
             if(nums[i]%mid==0)
             {
                sum+=(double)(nums[i]/mid);
             }
             else
             {
                sum+=(double)((nums[i]/mid)+1);
             }
        }
        if(sum<=threshold)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=0;
         for(auto it:nums)
         {
            maxi=max(maxi,it);
         }
         int low=1;
         int high=maxi;
         int ans=-1;
         while(low<=high)
         {
            int mid=(low+high)/2;
            if(func(mid,nums,threshold))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
         }
         return ans;
    }
};