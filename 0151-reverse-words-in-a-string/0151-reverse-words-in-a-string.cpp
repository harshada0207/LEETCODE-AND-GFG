class Solution {
public:
    
    string reverseWords(string s) {
        
        int i=0;
        int j=s.length()-1;
        while(s[i]==' ')
         {
            i++;
         }
        while(s[j]==' ')
        {
            j--;
        }
        string ans="";
        string temp="";
        while(i<=j)
        {
             if(s[i]!=' ')
             {
                temp+=s[i];
                i++;
             }
             else
             {
                if(s[i-1]==' ')
                {
                    i++;
                }
                else
                {reverse(temp.begin(),temp.end());
                ans+=temp;
                
                  ans+=' ';
                  temp="";
                  i++;
                }
             }
             
        
        }
        reverse(temp.begin(),temp.end());
        ans+=temp;
        reverse(ans.begin(),ans.end());
        return ans;
    }     

};