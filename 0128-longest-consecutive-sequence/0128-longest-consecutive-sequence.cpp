class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==1)
        {
            return 1;
        }
        map<int,bool>m;
        for(auto it:nums)
        {
            m[it]=0;
        }

      
        int maxi=0;
        int count=1;
        for(auto it :m)
        {
            if(it.second)
            {
                continue;
            }
            else
           { 
                int c=it.first;
                while(m.find(c+1)!=m.end())
                {
                    count++;
                    m[c]=1;
                    c++;

                }
                maxi=max(maxi,count);
                count=1;
           }

        }
        return maxi;
        
    }
};