class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int part_sum=0;
        int tsum=0;
 
        for (int i=0;i<minutes;i++)
        {
          part_sum+=customers[i];
        }
        for(int i=minutes;i<n;i++)
        {
            if(grumpy[i]==0)
            {
                tsum+=customers[i];
            }
        }
        int maxi=0;
        maxi=max(maxi,tsum+part_sum);
        int j=0;
        for(int i=minutes;i<n;i++)
        {
             
           if(grumpy[i]==0)
            {tsum-=customers[i];}
            
            if(grumpy[j]==0)
            {
                tsum+=customers[j];
            }

            part_sum+=customers[i];
            part_sum-=customers[j];
          
           maxi=max(maxi,tsum+part_sum);
              j++;
        }
        maxi=max(maxi,tsum+part_sum); 
        return maxi;
    }
};