class Solution {
public:
    // int solve(vector<int>v,int n,int ind,vector<vector<int>>&dp)
    // {
    //     if(ind==0)
    //     {
    //          if(n%v[ind]==0)
    //          {
    //             return n/v[ind];
    //          }
    //          else
    //          return 1e9;
    //     }
    //     if(dp[ind][n]!=-1)
    //     {
    //         return dp[ind][n];
    //     }
    //     int not_pick=solve(v,n,ind-1,dp);
    //     int pick=INT_MAX;
    //     if(v[ind]<=n)
    //     {
    //         pick=1+ solve(v,n-v[ind],ind,dp);
    //     }
    //     return  dp[ind][n]=min(not_pick,pick);
    // }
    int numSquares(int n) {
        int m=sqrt(n);
        //cout<<m;
        vector<int>v;
        for(int i=1;i<=m;i++)
        {
            v.push_back(i*i);
        }
        // for(int i=0;i<v.size();i++)
        // {
        //     cout<<v[i];
        // }
        
        int k=v.size();
        vector<vector<int>>dp(k,vector<int>(n+1,-1));
        for (int i = 0; i <= n; i++) 
        {
            if(i%v[0]==0)
             {
                dp[0][i]= i/v[0];
             }
             else
              {
                dp[0][i]= 1e9;
            }
            
            
        }

        for(int i=1;i<k;i++)
        {
            for(int j=0;j<=n;j++)
            {
                int not_pick=dp[i-1][j];
                int pick=1e9;
                if(v[i]<=j)
                {
                    pick = 1+dp[i][j-v[i]]; 
                }
                dp[i][j]=min(not_pick,pick);
                        
            }
        }
        return dp[k-1][n];
    }
};