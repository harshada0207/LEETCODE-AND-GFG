class Solution {
public:
    bool solve(int i, int j, string& s, string& p) {
        if (i < 0 && j < 0) {
            return true;
        }
        
        if (i < 0 && j >= 0) {
            return false;
        }
        
        if (p[i] == '*') {
            return solve(i - 2, j, s, p) || (j >= 0 && (p[i - 1] == s[j] || p[i - 1] == '.') && solve(i, j - 1, s, p));
        }
        
        if (j < 0) {
            return false;
        }
        
        if (p[i] == '.' || p[i] == s[j]) {
            return solve(i - 1, j - 1, s, p);
        }
        
        return false;
    }
    
    bool isMatch(string s, string p) {
        return solve(p.length() - 1, s.length() - 1, s, p);
    }
};

