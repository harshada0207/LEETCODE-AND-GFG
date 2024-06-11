class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>m;
      
       for(auto it: arr1)
       {
         m[it]++;
       }
       arr1.clear();
       for(int i=0;i<arr2.size();i++)
       {
         
             for(int k=0;k<m[arr2[i]];k++)
             {
                arr1.push_back(arr2[i]);
                
             }
             m.erase(arr2[i]);
          
       }
      for(auto it:m)
      {
          for(int i=0;i<it.second;i++)
             {
                arr1.push_back(it.first);
                
             }
      }

        return arr1;
    }
};