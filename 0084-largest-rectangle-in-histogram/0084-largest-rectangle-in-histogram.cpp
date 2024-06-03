class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int r[n];
        int l[n];
        int max_rec=0;
        stack<int>stk;

        for(int i=0;i<n;i++)
        {
            while(!stk.empty()&&heights[stk.top()]>=heights[i])
            {
                stk.pop();
            }
            if(stk.empty())
            {
                l[i]=-1;
            }
            else{
                l[i]=stk.top();//ja atk le skte ho vos trore kr rhe hai
            }
            stk.push(i);
        }
            
        while(!stk.empty())
        {
            stk.pop();
        }
        for(int k=n-1;k>=0;k--)
            {
                while(!stk.empty()&&heights[stk.top()]>=heights[k])
            {
                stk.pop();
            }
            if(stk.empty())
            {
                r[k]=n;
            }
            else{
                r[k]=stk.top();
            }
            stk.push(k);
            }
            
            
            for(int i=0;i<n;i++)
            {
                  max_rec=max(max_rec,((r[i]-1-l[i]-1+1)*heights[i]));
            }
            
           
            
        
        return max_rec;
    }
};