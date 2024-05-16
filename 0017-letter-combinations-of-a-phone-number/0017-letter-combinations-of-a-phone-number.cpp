class Solution {
public:
    void solve(string&s ,vector<string>&v,vector<string>&mp, int ind,string digits)
    {
        if(ind==digits.size())
        {
            v.push_back(s);
            return;
        }
        string letters=mp[digits[ind]-'0'];
        for(int i=0;i<letters.size();i++)
        {
            s.push_back(letters[i]);
            solve(s,v,mp,ind+1,digits);
            s.pop_back();
            
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>mp(10);
        mp[1]="";
        mp[0]="";
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        string s;
        vector<string>v; 
        if(digits=="")
        {
            return v;
        }
        solve(s,v,mp,0,digits);
        return v;      
    }
};