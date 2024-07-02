class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int>dp(n,1);
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pairs[i][0]>pairs[j][1])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            maxi=max(dp[i],maxi);


        }
        return maxi;
    }
};