class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int maxi = 0;

            for (int i = 0; i < n; ++i) {
                if (mat[i][mid] > mat[maxi][mid]) {
                    maxi = i;
                }
            }

            bool left = (mid == 0 || mat[maxi][mid] > mat[maxi][mid - 1]);
            bool right = (mid == m - 1 || mat[maxi][mid] > mat[maxi][mid + 1]);

            if (left && right) {
                return {maxi, mid};
            } else if (!left) { 
                high = mid - 1;
            } else { 
                low = mid + 1;
            }
        }

        return {-1, -1}; 
    }
};