class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int>m;
        int maxi=0;
        int i=0;
        for(int j=0;j<n;j++)
        {
            m[fruits[j]]++;
            while(m.size()>2 && i<=j)
            {
               m[fruits[i]]--;
               if(m[fruits[i]]==0)
               {
                  m.erase(fruits[i]);
               }
               i++;
            }
            maxi=max(maxi,j-i+1);
        }
        return maxi;
    }
};