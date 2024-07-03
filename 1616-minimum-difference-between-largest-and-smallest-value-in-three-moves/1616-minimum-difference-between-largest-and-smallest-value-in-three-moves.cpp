class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4) return 0;

        //sort the array
        sort(nums.begin(),nums.end());

        //applying 4 possibilities
        int ans1=nums[n-4]-nums[0];
        int ans2=nums[n-3]-nums[1];
        int ans3=nums[n-2]-nums[2];
        int ans4=nums[n-1]-nums[3];
        
        //finding minimum of them
        return min(min(ans1,ans2),min(ans3,ans4));
    }
};