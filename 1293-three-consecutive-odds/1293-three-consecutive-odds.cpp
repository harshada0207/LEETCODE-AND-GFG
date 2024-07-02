class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count=0;
        int j=0;
        while(j<arr.size())
        {
            if(arr[j]%2!=0)
            {
                count++;
                j++;
            }
            else
            {
                count=0;
                j++;
            }
            if(count==3)
            {
                return true;
            }
            
        }
        return false;
    }
};