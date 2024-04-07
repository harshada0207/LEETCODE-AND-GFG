class Solution {
public:
    void heapify(vector<int>&nums ,int n,int i)
    {
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && nums[largest]<nums[left])
        {
            largest=left;
        }
        if(right<n && nums[largest]<nums[right])
        {
            largest=right;
        }
        if(largest!=i)
        {
            swap(nums[largest],nums[i]);
            heapify(nums,n,largest);

        }
    }
    void heap_sort(vector<int>&nums ,int n)
    {
        for(int i=n/2-1;i>=0;i--)
        {
            heapify(nums,n,i);
        }
        int size=n-1;
        while(size>0)
        {
            swap(nums[0],nums[size]);
            
            heapify(nums,size,0);
            size--;
            
        }

    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=n/2-1;i>=0;i--)
        {
            heapify(nums,n,i);
        }
        
        heap_sort(nums,n);
        return nums;
        
    }
};