class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int>mp;
        for(auto it : dictionary)
        {
            mp[it]++;
        }
        int i=0;
        int j=0;
        string ans="";
        char c=' ';
        while(j<sentence.size())
        {    
            if(sentence[j]==c)
            {
                ans+=sentence.substr(i,j-i);
                ans+=" ";
                j++;
                i=j;
            }
            else
           { auto it=mp.find(sentence.substr(i,j-i+1));
             if(it!=mp.end())
             {
                ans+=it->first;
                ans+=" ";
             
             while(sentence[j]!=c && j<sentence.size())
             {
                j++;
             }
             j++;
             i=j;
             }
             else
             {
                j++;
             }
           }
        }
        if(i!=j)
        {
            
            ans+=sentence.substr(i,j-i+1);
        }
        else
        {
            ans.pop_back();
        }
        return ans;
        
    }
};