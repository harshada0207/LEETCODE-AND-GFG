class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

        vector<long long>vis(n,0);
        for(long long i=0;i<roads.size();i++)
        {
            vis[roads[i][0]]++;
            vis[roads[i][1]]++;
        }

        priority_queue<long long>pq;
        for(long long i=0;i<n;i++)
        {
            pq.push(vis[i]);
        }
        long long imp=n;
        long long sum=0;
        while(!pq.empty())
        {
            long long curr=pq.top();
            sum+=(long long)(curr*imp);
            pq.pop();
            imp--;
        }
        return sum;
        
    }
};