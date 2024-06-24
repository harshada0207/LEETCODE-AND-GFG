class Solution {
public:
   bool canweplace(int mid,vector<int>& position, int m)
   {
       int count=1;
       int last=position[0];
       for(int i=1;i<position.size();i++)
       {
          if(position[i]-last>=mid)
          {
             count++;
             last=position[i];
          }
       }
       if(count>=m)
       {
        return true;
       }
       return false;
   }
    int maxDistance(vector<int>& position, int m) {
          int n=position.size();
          sort(position.begin(),position.end());
          int maxi=position[n-1]-position[0];
          int low=1;
          int high=maxi;
          int ans=0;
          while(low<=high)
          {
            int mid=(low+high)/2;
            if(canweplace(mid,position,m))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
          }
          return ans;

    }
};