class Solution {
public:
int t[101][101];
int n,m,N;
    bool solve(int i,int j,string s1, string s2, string s3)
    {
        if(i==n && j==m && i+j==N)
        {
            return true;
        }
        if(i+j>=N)
        {
            return false;
        }
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
        bool result=false;
        if(i<n && s1[i]==s3[i+j])
        {
            result=solve(i+1,j,s1,s2,s3);
        }
        if(result==true)
        {
            return t[i][j]=true;
        }
        if(j<m && s2[j]==s3[i+j])
        {
            result=solve(i,j+1,s1,s2,s3);
        }
        return t[i][j]=result;
    }
    bool isInterleave(string s1, string s2, string s3) {
         n=s1.length();
          m=s2.length();
           N=s3.length();
           memset(t,-1,sizeof(t));
          if(n+m!=N)
          {
            return false;
          }
          return solve(0,0,s1,s2,s3);
        
    }
};