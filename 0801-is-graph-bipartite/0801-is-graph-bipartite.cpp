class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>&vis,int i,int color)
    {
        vis[i]=color;
        
            for(auto it:graph[i])
            {
                if(vis[it]==-1)
                {
                    if(color==1)
                    {
                         if(dfs(graph,vis,it,0)==false)
	                    {
	                        return false;
	                    }
                        
                    }
                    else
                    {
                        if(dfs(graph,vis,it,1)==false)
	                    {
	                        return false;
	                    }
                    }
                    
                }
                else
                {
                    if(vis[it]==color)
                    {
                        return false;
                    }
                    
                }
             }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>vis(V,-1);
        for(int i=0;i<V;i++)
	    {
	        if(vis[i]==-1)
	        {
	            
	            if(dfs(graph,vis,i,0)==false)
	            {
	                return false;
	            }
	        }
	    }
	    return true;
    }
};