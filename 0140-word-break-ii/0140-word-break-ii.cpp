class Solution {
public:
     void solve (string s,  unordered_map<string,int>&map,vector<string>&ans,int index,string s2)
    {
        if(index==s.size())
        {
          
             if (!s2.empty()) {
                s2.pop_back();
                ans.push_back(s2);
            }
            return;
        }
        // if(dp[index]!=-1)
        // {
        //     return dp[index];
        // }
        for(int i=index;i<s.size();i++)
        {
            if(map.find(s.substr(index,i-index+1))!=map.end())
            {
                string o=s2;
                string s3=s.substr(index,i-index+1);
                s2+=(s3);
                s2+=' ';
                solve(s,map,ans,i+1,s2);
                s2=o;
                
                
            }
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
         unordered_map<string,int>map;
         vector<string>ans;
        for(auto it:wordDict)
        {
            map[it]++;
        }
       // vector<int>dp(s.size(),-1);
       string s2="";
        solve(s,map,ans,0,s2);
        return ans;
    }
};