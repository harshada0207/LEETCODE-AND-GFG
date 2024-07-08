class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
       for(int i=0;i<n;i++)
       {
         q.push(i+1);
       }
       while(q.size()>1)
       {
           int counter=0;
           while(counter<k-1)
           {
                int c=q.front();
                q.pop();
                q.push(c);
                counter++;
           }
           q.pop();

       }
       return q.front();
    }
};