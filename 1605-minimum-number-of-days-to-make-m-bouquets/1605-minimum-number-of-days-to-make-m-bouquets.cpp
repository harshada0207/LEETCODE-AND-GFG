class Solution {
public:
    bool func(vector<int>& bloomDay,int ind, int m, int k)
    {
        int j=0;
     
        int counter=0;
        
        while(j<bloomDay.size())
             {
                if(bloomDay[j]<=ind)
                {
                    counter++;
                    j++;

                    
                }
                else
                {
                   if(counter==k)
                   {
                       m--;
                   }
                   else if(counter>k)
                   {
                     m-=(counter/k);
                   }
                   counter=0;
                   j++;
                }

             }
              if(counter==k)
                   {
                       m--;
                   }
                   else if(counter>k)
                   {
                     m-=(counter/k);
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
        int mini=INT_MAX;
        for(auto it:bloomDay)
        {
            maxi=max(maxi,it);
            mini=min(mini,it);
        }
         int low=mini;
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