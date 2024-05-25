class Solution {
public:
    bool solve(int i, int j, string& s, vector<vector<int>>& dp) {
        if (i >= j) {
            return true;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == s[j]) {
            return dp[i][j] = solve(i + 1, j - 1, s, dp);
        }
        return dp[i][j] = false;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int maxLen = 0;
        int start = 0;

        for (int len = 1; len <= n; len++) { // Length of the substring
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (solve(i, j, s, dp)) {
                    if (len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};
