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
                
                  maxi=max(maxi,j-i+1);
            }
            else
            {
                while(nums[i]!=0)
                {
                    i++;
                    
                }
                i++;
                 maxi=max(maxi,j-i+1);
            }
           
            j++;
        }
        return maxi;
    }
};