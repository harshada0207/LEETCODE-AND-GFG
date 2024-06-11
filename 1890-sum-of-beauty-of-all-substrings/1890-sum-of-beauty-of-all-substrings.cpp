class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;
                
                int mini = INT_MAX;
                int maxi = INT_MIN;
                for (auto &p : mp) {
                    mini = min(mini, p.second);
                    maxi = max(maxi, p.second);
                }
                
                //if (mini != INT_MAX && maxi != INT_MIN) {
                    sum += (maxi - mini);
               // }
            }
        }

        return sum;
    }
};