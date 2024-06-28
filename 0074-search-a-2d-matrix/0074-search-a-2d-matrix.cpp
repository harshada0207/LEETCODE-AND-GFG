class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int set_row=-1;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
             if(target>=matrix[i][0]&&target<=matrix[i][n-1])
             {
                set_row=i;
             }
        }
        if(set_row==-1)
        {
            return false;
        }
      

        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(matrix[set_row][mid]==target)
            {
                return true;
            }
            else if(matrix[set_row][mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return false;
        
        
    }
};