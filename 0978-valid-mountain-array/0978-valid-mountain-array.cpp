class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int count=0;
        int flag=0;

        for(int i=0;i<arr.size()-1;i++)
        {
              if(arr[i+1]==arr[i])
              {
                return false;
              }
             if(flag==0)
              {
                if(arr[i+1]<arr[i])
                {
                    if(i==0)
                    {
                        return false;
                    }
                    flag=1;
                    count++;
                }
              }
              else
              {
                if(arr[i+1]>arr[i])
                {
                    flag=0;
                    count++;
                }
              }
        }
        return count==1 ;
    }
};