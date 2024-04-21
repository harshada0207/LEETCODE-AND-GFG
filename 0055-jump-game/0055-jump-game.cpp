class Solution {
public:
    bool canJump(vector<int>& nums) {
    
    int n=nums.size();
    int j=n-1;
    int i=n-2;
    while(i>=0)
    {
       
        if(nums[i]>=j-i)
        {
            j=i;
            
        }
        
        i--;
        

       
    }
    if(j==0)
    {
        return true;
    }
    return false;

    }
};