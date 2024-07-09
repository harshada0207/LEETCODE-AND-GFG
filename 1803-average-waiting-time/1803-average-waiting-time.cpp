class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int curr_time=customers[0][0];
        double ans=0;
        for(int i=0;i<customers.size();i++){
              if(customers[i][0]>curr_time)
              {
                 curr_time=customers[i][0];
              }
              curr_time=curr_time+customers[i][1];
              int wait=curr_time-customers[i][0];
              ans+=wait;
        }
        return double(ans/customers.size());
       
    }
};