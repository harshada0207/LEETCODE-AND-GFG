class Solution {
public:
    int max_el(vector<int>& piles)
    {
        int maxi=0;
        for(int i=0;i<piles.size();i++)
        {
             maxi=max(piles[i],maxi);
        }
        return maxi;
    }
    bool solve(vector<int>& piles,int mid,int h)
    {
        double time=0;
        for(int i=0;i<piles.size();i++)
        {
              if(piles[i]%mid==0)
              {
                  time+=piles[i]/mid;
              }
              else
              {
                time+=(piles[i]/mid)+1;
              }
        }
        if(time>h)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1;
        int j=max_el(piles);
        int ans=0;
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            if(solve(piles,mid,h))
            {
                ans=mid;
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
        }
        return ans;
        
    }
};