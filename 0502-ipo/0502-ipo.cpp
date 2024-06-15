class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;
        int n=capital.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
           cout<<"("<< v[i].first<<" "<<v[i].second<<")";
        }
        cout<<endl;
        priority_queue<pair<int,int>>pq;
        int ind=0;
        int profit=0;
        while(k>0 && (ind<n  || !pq.empty()))
        {
            
            while(ind <n && v[ind].first<=w)
            {
                  pq.push({v[ind].second,v[ind].first});
                  ind++;
            }
            if(!pq.empty())
            {w+=pq.top().first;
            cout<<pq.top().first<<", "<<pq.top().second;
            pq.pop();
            k--;
            }
            else
            {
                break;
            }

        }
        return w;
        
    }
};