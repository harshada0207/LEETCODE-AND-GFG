class Solution {
public:
    void dfs(int sr, int sc,vector<vector<int>>& ans,vector<vector<int>>& image,int color,int inicolor)
    {
        int n=image.size();
        int m=image[0].size();
        ans[sr][sc]=color;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int k=0;k<4;k++)
        {
            int nrow=sr+delrow[k];
            int ncol=sc+delcol[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==inicolor && ans[nrow][ncol]!=color)
            {
                dfs(nrow,ncol,ans,image,color,inicolor);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       
        int n=image.size();
        int m=image[0].size();
         vector<vector<int>>ans=image;
         int inicolor=image[sr][sc];
         dfs(sr,sc,ans,image,color,inicolor);
         return ans;
    }
};