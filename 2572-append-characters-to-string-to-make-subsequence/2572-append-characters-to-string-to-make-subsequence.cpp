class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0;int j=0;
        while(j<t.size())
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
            if(i>s.length())
            {
                break;
            }
        }
        if(j==t.size())
        {
            return 0;
        }
        return t.size()-j;
    }
};