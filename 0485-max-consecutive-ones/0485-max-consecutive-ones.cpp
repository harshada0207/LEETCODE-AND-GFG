class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0;
        int j=0;
        int count=0;
        int maxi=0;
        while(j<nums.size())
        {
            if(nums[j]==1)
            {
                 count++;
            }
            else
            {
                while(nums[i]!=0)
                {
                    i++;
                    
                }
                i++;
                count=0;
            }
            maxi=max(maxi,count);
            j++;
        }
        return maxi;
    }
};