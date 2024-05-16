class Solution {
public:
   bool isParanthesis(int index,int i,string s)
   {
      while(index<=i)
      {
          if(s[index++]!=s[i--])
          {
            return false;
          }
      }
      return true;
   }
    void solve(vector<vector<string>>&ans,vector<string>&path,string s,int index,int n)
    {
        if(index==n)
        {
            ans.push_back(path);
            return;
        }
        for(int i=index;i<n;i++)
        {
            if(isParanthesis(index,i,s))
            {
                path.push_back(s.substr(index,i-index+1));
                solve(ans,path,s,i+1,n);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        int n=s.length();
        solve(ans,path,s,0,n);
        return ans;
    }
};