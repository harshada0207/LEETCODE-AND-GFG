class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
           vector<int>min_freq(26,INT_MAX);
           for(int j=0;j<words.size();j++)
           {
               vector<int>freq(26,0);
               for(int i=0;i<words[j].size();i++)
               {
                  freq[words[j][i]-'a']++;
                  
               }
               for(int k=0;k<26;k++)
               {
                  min_freq[k]=min(min_freq[k],freq[k]);
               }
           }
           vector<string>ans;
            for(int k=0;k<26;k++)
               {
                  if(min_freq[k]>0)
                  {
                      for(int i=0;i<min_freq[k];i++)
                      {
                          ans.push_back(string(1,'a'+k));
                      }
                  }
               }
               return ans;
        
        
    }
};