class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int mid=0;
        while(mid<=high)
        {
           if(nums[mid]==1)
           {
                 mid++;
           }
           else if(nums[mid]==0)
           {
             swap(nums[low],nums[mid]);
             low++;
             mid++;
           }
           else
           {
             swap(nums[high],nums[mid]);
             high--;
             //jo swap hua uski checking reh jati isiliye yaha mid++ nahi kia.
             
           }
        }
        
    }
};