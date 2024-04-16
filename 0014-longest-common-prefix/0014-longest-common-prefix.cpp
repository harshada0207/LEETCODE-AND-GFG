class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1)
        {
            return strs[0];
        }
        string comparator=strs[0];
        if(strs[0].size()==0)
        {
            return "";
        }
        int end=INT_MAX;
        for(int i=1;i<strs.size();i++)
        {
            int j=0;
            int e=-1;
            if(strs[i].size()==0)
        {
            return "";
        }
            while(j<strs[i].size())
            {
                if(comparator[j]!=strs[i][j])
                {
                    break;
                }
                else
                {
                    e=j;
                }
                j++;
               
            }
            if(e==-1)
                {
                    return "";
                }
            end=min(e,end);
            
        }
        return comparator.substr(0,end-0+1);

        
    }
};