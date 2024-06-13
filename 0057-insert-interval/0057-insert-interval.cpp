class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        if(n==0)
        {
            return {{newInterval[0],newInterval[1]}};
        }
         vector<vector<int>>ans;
         int i=0;
        for(i=0;i<n;i++)
        {
            if(intervals[i][0]<newInterval[0])
            {
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
            else
            {
               
                ans.push_back({newInterval[0],newInterval[1]});
                break;
            }
         
        }
        if(ans.size()==n)
        {
            ans.push_back({newInterval[0],newInterval[1]});
        }
        while(i<=n-1)
        {
            
            ans.push_back({intervals[i][0],intervals[i][1]});
            i++;
            
        }
        for(int k=0;k<ans.size();k++)
        {
            cout<<"("<<ans[k][0]<<" "<<ans[k][1]<<")";
        }
         vector<vector<int>>ans2;
         ans2.push_back({ans[0][0],ans[0][1]});
         for(int j=1;j<ans.size();j++)
         {
                int n=ans2.size()-1;
                if(ans[j][0]>ans2[n][1])
                {
                    ans2.push_back({ans[j][0],ans[j][1]});
                }
                else if(ans[j][0]==ans2[n][1])
                {
                    ans2[n][1]=ans[j][1];
                }
                else
                {
                    if(ans[j][1]>ans2[n][1])
                    {
                        ans2[n][1]=ans[j][1];
                    }
                    else
                    {
                        continue;
                    }
                }
         }
         return ans2;

    }
};