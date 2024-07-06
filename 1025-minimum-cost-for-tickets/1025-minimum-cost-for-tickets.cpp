class Solution {
public:
int dp[366][396];
int solve(int n,vector<int>& days, vector<int>& costs,int ind,int curr)
{
    if(ind>=n)
    {
        return 0;
    }
    
   if(dp[ind][curr]!=-1)
   {
     return dp[ind][curr];
   }
     int one=1e9;
     int two=1e9;
     int three=1e9;
     int t=1e9;

  if(days[ind]>curr)
   { one=costs[0]+solve(n,days,costs,ind+1,days[ind]);
     
   
     two=costs[1]+solve(n,days,costs,ind+1,days[ind]+6);
    
     
     three=costs[2]+solve(n,days,costs,ind+1,days[ind]+29);
    
   }
    else
    {
       t=0+solve(n,days,costs,ind+1,curr);
    }
    return dp[ind][curr]=(min({one,two,three,t}));

}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        memset(dp,-1,sizeof(dp));
        solve(n,days,costs,0,0);
        return dp[0][0];


    }
};