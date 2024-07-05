class Solution {
public:
    string minWindow(string s, string t) {
        int m=t.size();
        int hash[256]={0};
        for(int i=0;i<m;i++)
        {
            hash[t[i]]++;
        }
        int l=0;
        int r=0;
        int cnt=0;

        int min_len=1e9;
        int sindex=-1;
        while(r<s.size())
        {
            if(hash[s[r]]>0)
            {
                cnt++;
            }
            hash[s[r]]--;
            while(cnt==m)
            {
                if(r-l+1<min_len)
                {
                    min_len=r-l+1;
                    sindex=l;

                }
                hash[s[l]]++;
                if(hash[s[l]]>0)
                {
                    cnt=cnt-1;
                }
                l++;
            }
            r=r+1;
        }
        return sindex== -1 ? "":s.substr(sindex,min_len);
    }
};