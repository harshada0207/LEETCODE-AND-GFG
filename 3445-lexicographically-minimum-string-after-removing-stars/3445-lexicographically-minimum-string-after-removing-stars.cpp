class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        vector<int>ans;
        unordered_map<char,vector<int>>mp;
        priority_queue<char,vector<char>,greater<char>>pq;

        for(int i=0;i<n;i++)
        {
            if(s[i]!='*')
            {
               
                mp[s[i]].push_back(i);
                pq.push(s[i]);
            }
            else
            {
                ans.push_back(i);
                ans.push_back(mp[pq.top()].back());
                mp[pq.top()].pop_back();
                
                pq.pop();
                
                
            }
            
        }
        sort(ans.begin(),ans.end());
        for(int i=ans.size()-1;i>=0;i--)
        {
            s.erase(ans[i],1);
        }
        return s;
        
    }
};