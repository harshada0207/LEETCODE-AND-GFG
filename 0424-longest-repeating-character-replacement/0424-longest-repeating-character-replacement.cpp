class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>m;
        int i=0;
        int maxi=INT_MIN;
        int mlen=INT_MIN;
        for(int j=0;j<s.size();j++)
        {
               m[s[j]]++;
               maxi=max(maxi,m[s[j]]);
               if((j-i+1)-maxi>k)
               {
                  m[s[i]]--;
                  i++;
                  
               }
               else
               {
                  mlen=max(mlen,j-i+1);
               }

        }
        return mlen;

        
    }
};