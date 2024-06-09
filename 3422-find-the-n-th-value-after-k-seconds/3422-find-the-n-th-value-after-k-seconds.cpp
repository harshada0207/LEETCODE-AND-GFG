class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<int>a(n,1);
        int t=0;
        while(t<k)
        {
            long long sum=1;
            for(int i=1;i<n;i++)
            {
                 sum=(sum+a[i])%MOD;
                 a[i]=sum;
            }
          
            t++;
        }
        return a[n-1];
    }
};