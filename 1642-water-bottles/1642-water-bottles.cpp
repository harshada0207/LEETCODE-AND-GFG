class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
      int e_bottle=numBottles;
      int ans=numBottles;
      while(e_bottle>=numExchange)
      {
           int can_be_exchange=(e_bottle/numExchange)*numExchange;
           int get_bottle=e_bottle/numExchange;
           ans+=get_bottle;
           e_bottle-=can_be_exchange;
           e_bottle+=get_bottle;
      }
      return ans;
    }
};