class Solution {
public:
   int solve(int mid,vector<int>& weights, int days)
   {
        int count=0;
        int sum=0;
        int j=0;
        while(j<weights.size())
        {
              sum+=weights[j];
              if(sum==mid)
              {
                sum=0;
                count++;
                j++;
              }
              else if(sum>mid)
              {
                count++;
                sum=0;
              }
              else
              {
                j++;
              }

        }
        if(sum!=0 && sum<mid)
        {count++;}
        if(count>days)
        {
            return false;
        }
        return true;
   }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0;
        int max_wt=0;
        for(int i=0;i<n;i++)
        {
            sum+=weights[i];
            max_wt=max(max_wt,weights[i]);


        }
    
        int low=max_wt;
        int high=sum;
        int ans=0;
        int mid=0;
        while(low<=high)
        {
             mid=(low+high)/2;
            if(solve(mid,weights,days))
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