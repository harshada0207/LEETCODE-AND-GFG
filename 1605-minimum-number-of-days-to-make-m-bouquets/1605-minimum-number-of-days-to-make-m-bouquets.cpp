class Solution {
public:
    bool func(vector<int>& bloomDay,int ind, int m, int k)
    {
        int j=0;
        int i=0;
        while(j<bloomDay.size())
             {
                if(bloomDay[j]<=ind)
                {
                    if(j-i+1==k)
                    {
                        m--;
                        j++;
                        i=j;
                    }

                    else
                    {
                        j++;
                    }
                }
                else
                {
                   
                    
                    j++;
                    i=j;

                }

             }
             if(m<=0)
             {
                return 1;
             }
             return 0;
        
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int maxi=0;
        for(auto it:bloomDay)
        {
            maxi=max(maxi,it);
        }
         int low=1;
         int high=maxi;
         int ans=-1;
         while(low<=high)
         {
            int mid=low+((high-low)/2);
            if(func(bloomDay,mid,m,k)==true)
            {
                ans=mid;
                high=mid-1;
            }
            else 
            {
                low=mid+1;
            }
            
         }
        
        return ans;
    }
};