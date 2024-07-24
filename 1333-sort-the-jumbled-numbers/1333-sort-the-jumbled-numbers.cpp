class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
     priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;

        //unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            int num2=0;
            int num3=nums[i];
            int c=0;
            if(num3==0)
            {
                pq.push({{mapping[0],i},0});
            }
            else
           { while(num3!=0)
            {
                int k=(num3%10);
                num3=num3/10;
                num2+=mapping[k]*pow(10,c);
                c++;
              
            }
           
           // mp[nums[i]]=num2;
            pq.push({{num2,i},nums[i]});
           }
        }
        vector<int>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};