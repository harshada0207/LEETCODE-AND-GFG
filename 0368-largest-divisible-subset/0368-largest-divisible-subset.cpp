class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
         vector<int>hash(n);
         for(int i=0;i<n;i++)
         {
            hash[i]=i;
         }
         int maxi=0;
         int last_ind=0;
        for(int i=0;i<n;i++)
        {
            
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]%nums[prev]==0)
                {
                    if(dp[prev]+1>dp[i])
                    {
                        dp[i]=dp[prev]+1;
                        hash[i]=prev;
                    }
                }
            }

           if(dp[i]>maxi)
           {
              maxi=dp[i];
              last_ind=i;
           }


        }

        vector<int>a;
        a.push_back(nums[last_ind]);
        while(hash[last_ind]!=last_ind)
        {
            
            last_ind=hash[last_ind];
            a.push_back(nums[last_ind]);
        }
        return a;
        
    }
};