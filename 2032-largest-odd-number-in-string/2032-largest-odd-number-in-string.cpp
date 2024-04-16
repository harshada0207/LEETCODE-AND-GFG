class Solution {
public:
   int charToInt(char c) {
    return c - '0';
}
    string largestOddNumber(string num) {
        string ans="";
        int s=0;
        int e=0;
        int j=0;
        while(j<num.size())
        {
            if(charToInt(num[j])%2==1)
            {
                e=j;
                

            }
            j++;
        }
        if(e==0 && charToInt(num[0])%2==0)
        {
            return "";
        }
        return num.substr(s,e-s+1);
        
    }
};