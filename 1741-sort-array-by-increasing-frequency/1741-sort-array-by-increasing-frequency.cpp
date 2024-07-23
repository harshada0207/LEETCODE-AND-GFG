class Solution {
public:
    static bool cmp (pair<int,int>a,pair<int,int>b)
    {
        if(a.second==b.second)
        {
            return a.first>b.first;
        }
        return a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        vector<pair<int,int>>sorting;
        vector<int>ans;
        for(auto it:mp)
        {
            sorting.push_back({it.first,it.second});
        }
        sort(sorting.begin(),sorting.end(),cmp);
        for(int i=0;i<sorting.size();i++)
        {
            for(int j=0;j<sorting[i].second;j++)
            {
                ans.push_back(sorting[i].first);
            }
            
        }
        return ans;
        
    }
};