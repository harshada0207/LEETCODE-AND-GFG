class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        vector<int>prefix_sum;
        
      
        int i=0;
        int j=0;
        int sum=0;
        while(j<nums.size())
        {
            sum+=nums[j];
            
               
                
               
            while(sum>=target && i<=j)
            {
                ans=min(ans,j-i+1);
                sum-=nums[i];
                
                i++;
            }
            
            
            j++;
        }
        if(ans==INT_MAX)
        {
            return 0;
        }
        return ans;
        
    }
};