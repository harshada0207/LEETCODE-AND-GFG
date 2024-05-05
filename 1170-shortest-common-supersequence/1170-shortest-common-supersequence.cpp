class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
            
        }
        for(int i=0;i<=m;i++){
            
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }

        }
        string s="";
        int i=n;
        int j=m;
        while(i>0&&j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                s+=str1[i-1];
                i=i-1;
                j=j-1;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                
                s+=str1[i-1];
                i=i-1;
            }
            else
            {
                
                s+=str2[j-1];
                j=j-1;
            }
        }
       
        if(i==0&& j!=0)
        {
            while(j!=0)
            {
                s+=str2[j-1];
                j--;
            }
        }
        if(j==0&& i!=0)
        {
            while(i!=0)
            {
                s+=str1[i-1];
                i--;
            }
        }
         reverse(s.begin(),s.end());
       
        return s;
    }
};