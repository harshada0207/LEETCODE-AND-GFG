class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<vector<int>>revGraph(v);
        for(int i=0;i<v;i++)
        {
            for(auto it:graph[i])
           {  
              revGraph[it].push_back(i);
           
           }
        }
         vector<int>indegree(v,0);
        for(int i=0;i<v;i++)
        {
            for(auto it:revGraph[i])
            { 
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>safeNodes;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it:revGraph[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};