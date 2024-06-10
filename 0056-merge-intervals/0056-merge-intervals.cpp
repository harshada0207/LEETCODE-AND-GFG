class Solution {
public:
    static bool cmp (pair<int,int>a,pair<int,int>b)
    {
        if(a.first==b.first)
        {
            return a.second<b.second;
        }
        return (a.first<b.first);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int,int>>v;
        for(int i=0;i<intervals.size();i++)
        {
            v.push_back({intervals[i][0],intervals[i][1]});
        }
        sort(v.begin(),v.end(),cmp);
        vector<vector<int>>ans;
        ans.push_back({v[0].first,v[0].second});
        for(int i=1;i<v.size();i++)
        {
            int n=ans.size();
            if(v[i].first>ans[n-1][1])
            {
                ans.push_back({v[i].first,v[i].second});
            }
            else
            {
                if(v[i].second>ans[n-1][1])
                 {
                    ans[n-1][1]=v[i].second;
                 }
                //  if(v[i].first<ans[n-1][0])
                //  {
                //     ans[n-1][0]=v[i].first;
                //  }

                 
                
            }
        }
        return ans;
    }
};