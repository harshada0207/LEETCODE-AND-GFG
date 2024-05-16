class Solution {
public:
    bool solve (string s,  unordered_map<string,int>&map,vector<int>&dp,int index)
    {
        if(index==s.size())
        {
            return true;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        for(int i=index;i<s.size();i++)
        {
            if(map.find(s.substr(index,i-index+1))!=map.end())
            {
              
                if(solve(s,map,dp,i+1))
                {
                    return dp[index]=true;
                }
            }
        }
        return dp[index]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>map;
        for(auto it:wordDict)
        {
            map[it]++;
        }
        vector<int>dp(s.size(),-1);
        return solve(s,map,dp,0);
    }
};