class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        priority_queue<pair<int,string>>pq;
        int n=heights.size();
        for(int i=0;i<n;i++)
        {
            pq.push({heights[i],names[i]});

        }
        vector<string>v;
        while(!pq.empty())
        {
            pair<int,string> p=pq.top();
            pq.pop();
            v.push_back(p.second);

        }
        return v;
    }
};