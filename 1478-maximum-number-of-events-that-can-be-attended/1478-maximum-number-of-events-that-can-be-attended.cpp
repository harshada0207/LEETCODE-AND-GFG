class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        vector<pair<int,int>>v;
        for(int i=0;i<events.size();i++)
        {
            v.push_back({events[i][1],events[i][0]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       
        int count=0;
        int curr_time=0;
        int ind=0;
        while(!pq.empty()||ind<events.size())
        {
            if(pq.empty() && v[ind].second>curr_time)
            {
                curr_time=v[ind].second;
                

            }
            while(ind<events.size() && v[ind].second<=curr_time)
            {
                pq.push(v[ind]);
                ind++;
            }
           
          
                pq.pop();
                count++;
                curr_time++;  // Move to the next day
            
             while(!pq.empty()&&pq.top().first<curr_time)
            {
                pq.pop();
            }
        }

        return count;
    }
};