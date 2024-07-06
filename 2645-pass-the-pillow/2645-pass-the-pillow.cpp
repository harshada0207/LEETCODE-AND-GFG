class Solution {
public:
    int passThePillow(int n, int time) {
        int t=0;
        int m=0;
        int flag=0;
        while(t!=time)
        {
             if(flag==0)
             {
                m++;
                if(m==n-1)
                {
                    flag=1;
                }
                
             }
             else
             {
                m--;
                if(m==0)
                {
                    flag=0;
                }
             }
             t++;
        }
        return m+1;
    }
};