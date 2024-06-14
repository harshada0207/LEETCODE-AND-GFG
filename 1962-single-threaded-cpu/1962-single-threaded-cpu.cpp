class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<pair<pair<int,int>,int>>v;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<tasks.size();i++)
        {
            v.push_back({{tasks[i][0],tasks[i][1]},i});
        }
        sort(v.begin(),v.end());

        
        long long curr_time=0;
        int ind=0;
         vector<int>ans;
        while(!pq.empty()|| ind<n)
        {

            if(pq.empty() && v[ind].first.first>curr_time)
            {
                curr_time=v[ind].first.first;
               
              
            }
           
           
            while(ind<n && v[ind].first.first<=curr_time)
            {
                 pq.push({v[ind].first.second,v[ind].second});
                 ind++;
            }
            pair<int,int>on_process=pq.top();
            pq.pop();
            curr_time+=on_process.first;
            ans.push_back({on_process.second});

        }

        return ans;
    }
};