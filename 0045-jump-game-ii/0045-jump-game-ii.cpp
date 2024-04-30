class Solution {
public:
    int jump(vector<int>& nums) {
        int i=nums.size()-1;
        int mini=0;

        while(i>0)
        {
              int j=i-1;
              int pos=i;
              while(j>=0)
              {
                if(nums[j]>=i-j)
                {
                    pos=j;
                }
                j--;
              }
              i=pos;
              mini++;
        }
        return mini;
        
    }
};