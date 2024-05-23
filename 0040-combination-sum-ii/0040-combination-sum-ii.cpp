class Solution {
public:
    void findcombi(int ind,vector<int>&candidates,int target,vector<vector<int>>&ans,vector<int>&store)
    {
        
    
            if(target==0)
            {
               
               ans.push_back(store);
               return;
            }
           
        
            for (int i = ind; i < candidates.size(); ++i) {
             if (i > ind && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) {
                // No need to proceed further as the candidates are sorted
                break;
            }
            store.push_back(candidates[i]);
            findcombi(i + 1, candidates, target - candidates[i], ans, store);
            store.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>store;
        sort(candidates.begin(),candidates.end());
        findcombi(0,candidates,target,ans,store);
        
       return ans; 
    }
};