class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        unordered_map<int,int>m;
        m[0]=-1;
        if(k==1)
        {
            if(nums.size()>1)
            {return true;}
            else
            {
                return false;
            }
        }
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int p=0;
            while(p*k<=sum)
            {
                if(m.find(sum-p*k)!=m.end() && i-m[sum-p*k]-1+1>1)
                {
                    return true;
                }
                p++;
            }
            if(m.find(sum)==m.end())
            {m[sum]=i;}
        }
        return false;
        
    }
};