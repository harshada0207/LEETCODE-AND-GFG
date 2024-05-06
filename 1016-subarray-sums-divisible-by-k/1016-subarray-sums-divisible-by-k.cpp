class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        // int arr2[n];
        // int sum=0;
        // for(int i=0;i<n;i++)
        // {
        //     sum+=nums[i];
        //     arr2[i]=sum;
        // }
        // int count=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(arr2[i]%k==0)
        //         {
        //             count++;
        //         }
          
        //     for(int j=i+1;j<n;j++)
        //     {
                
        //         if((arr2[i]-arr2[j])%k==0)
        //         count++;
        //     }
        // }
        // return count;
        unordered_map<int,int>mp;
        mp[0]++;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
             sum+=nums[i];
             int rem=sum%k;
             if(rem<0)
             {
                rem=k+rem;
             }
             if(mp.find(rem)!=mp.end())
             {
                ans+=mp[rem];

                
             }
             mp[rem]++;
        }
        return ans;


    }
};