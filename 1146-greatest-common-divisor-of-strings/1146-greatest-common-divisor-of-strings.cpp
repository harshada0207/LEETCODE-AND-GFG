class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1)
        {
            return "";
        }
        int n=str1.length();
        int m=str2.length();
        int x=min(n,m);
        while(x)
        {
            if(n%x==0 && m%x==0)//piche se start krna easy tha
            {
                break;
            }
            x--;
        }
        return str1.substr(0,x);
        
    }
};