class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        multiset<int>st;
        int i=0;
        int j=0;
        int n=nums.size();
        int maxLength=0;
        while(j<n)
        {
            st.insert(nums[j]);
            while(*st.rbegin()-*st.begin()>limit && i<=j)
            {
                st.erase(st.find(nums[i]));
                i++;
            }
            maxLength=max(maxLength,j-i+1);
            j++;
        }
        return maxLength;
        
    }
};