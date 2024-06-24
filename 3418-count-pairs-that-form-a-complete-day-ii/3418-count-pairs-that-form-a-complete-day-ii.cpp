
#define ll long long int
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        
        int n=hours.size();
        unordered_map<int,ll>m;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            if(m.find(((24-hours[i]%24)%24))!=m.end())
            {
                ans+=m[(24-hours[i]%24)%24];
            }
            m[hours[i]%24]++;
        }
        
        return ans;

        
    }
};