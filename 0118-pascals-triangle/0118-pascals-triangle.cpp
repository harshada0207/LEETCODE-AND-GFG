class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        ans[0]={1};
        if(numRows==1)
        {
           return ans;
        }
        ans[1]={1,1};
        if(numRows==2)
        {
           return ans;
        }
        int counter=2;
        while(counter<numRows)
        {
            vector<int>curr(counter+1);
            vector<int>prev=ans[counter-1];
            curr[0]=1;
            for(int i=1;i<curr.size()-1;i++)
            {
                curr[i]=prev[i-1]+prev[i];
            }
            curr[curr.size()-1]=1;
            ans[counter]=curr;
            counter++;
        }

        return ans;
    }
};