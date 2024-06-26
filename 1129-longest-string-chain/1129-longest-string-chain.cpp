class Solution {
public:
    bool check(string s1, string s2)
    {
        int i=0;
        int j=0;
        int n=s1.size();
        int m=s2.size();
        if(n!=m+1)
        {
            return false;
        }
        while(i<n)
        {
            if(j<m && s1[i]==s2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
         if(i==n && j==m)
         {
            return true;
         }
         return false;

    }
    static bool cmp(string s1,string s2)
    {
        return s1.size()<s2.size();
    } 
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n=words.size();
        vector<int>dp(n+1,1);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(check(words[i],words[j]))
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            ans=max(dp[i],ans);

        }
        return ans;
        
    }
};