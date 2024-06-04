class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n);
        int p=0;
        int ng=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                arr[p]=nums[i];
                p+=2;
            }
            else 
            {
                arr[ng]=nums[i];
                ng+=2;
            }
        }

        return arr;
    }
};