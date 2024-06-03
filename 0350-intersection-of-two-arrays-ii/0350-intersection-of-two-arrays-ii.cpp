class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       
        unordered_map<int,int>mp;
        vector<int>ans;
         for(int j=0;j<nums1.size();j++)
        {
            mp[nums1[j]]++;
        }
        for(int j=0;j<nums2.size();j++)
        {
            if(mp.find(nums2[j])!=mp.end())
            {
                 ans.push_back(nums2[j]);
                 mp[nums2[j]]--;
                 if(mp[nums2[j]]==0)
                 {
                    mp.erase(nums2[j]);
                 }
            }
        }
        return ans;
        
        
    }
};