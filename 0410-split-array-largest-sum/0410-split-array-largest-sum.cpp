class Solution {
public:
int canweallocate(int mid,int m,vector<int>& arr,int n)
{
    int student=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
       if(sum>mid)
        {
            sum=arr[i];
            student++;
        }
        
    }
    
   
    if(student>m)
    {
        return 1;
    }
    else{
        return 0;
    }
}

    int splitArray(vector<int>& nums, int k) {
      if(nums.size()<k)
    {
        return -1;
    }
    //sort(arr.begin(),arr.end());
    int q=accumulate(nums.begin(),nums.end(),0);
    int maxi=0;
    for(auto it:nums)
    {
         maxi= max(maxi,it);
    }
    int low=maxi;
    int high=q;
    int ans=0;
    while(low<=high)
    {
        int mid=(low+high)/2;
        //cout<<mid<<" ";
        if(canweallocate(mid,k,nums,nums.size())==1)
        {
             low=mid+1;
        }
        else {
        
            high=mid-1;
        }
    }
    return low;
   
    }
};