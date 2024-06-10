class Solution {
public:
    int trap(vector<int>& height) {
         int n=height.size();
        int res=0;
        int lm[n];
         int rm[n];
        lm[0]=height[0];
        rm[n-1]=height[n-1];
        for(int i=1;i<n;i++)
        {
            lm[i]=max(height[i],lm[i-1]);
            rm[n-i-1]= max(height[n-i-1],rm[n-i]);

        }

        // rm[n-1]=height[n-1];
        //  for(int i=n-2;i>=0;i--)
        // {
        //     rm[i]= max(height[i],rm[i+1]);

        // }
        for(int i=0;i<n-1;i++)
        {
            res= res+(min(rm[i],lm[i])-height[i]);
        }
        return res;
    }
};