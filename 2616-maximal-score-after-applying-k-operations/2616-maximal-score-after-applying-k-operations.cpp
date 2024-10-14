class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score=0;
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        while(k>0)
        {
            int m=pq.top();
    
            pq.pop();
            score+=m;
            
            if(m%3==0)
            {
                pq.push(m/3);
            }
            else
            {
                pq.push(m/3 +1);
            }
            k--;
            
        }
        return score;
    }
};