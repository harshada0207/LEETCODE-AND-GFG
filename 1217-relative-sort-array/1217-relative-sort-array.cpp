class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>m;
        vector<int>ans;
       for(auto it: arr1)
       {
         m[it]++;
       }
       for(int i=0;i<arr2.size();i++)
       {
         
             for(int k=0;k<m[arr2[i]];k++)
             {
                ans.push_back(arr2[i]);
                
             }
             m.erase(arr2[i]);
          
       }
      for(auto it:m)
      {
          for(int i=0;i<it.second;i++)
             {
                ans.push_back(it.first);
                
             }
      }

        return ans;
    }
};