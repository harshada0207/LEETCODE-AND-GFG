class Solution {
public:
   int histo(vector<int>&heights)
   {
    int n=heights.size();
      int lm[n];
      int rm[n];
      stack<int>st;
      for(int i=0;i<n;i++)
      {
        while(!st.empty() && heights[st.top()]>=heights[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            lm[i]=0;
        }
        else
        {
            lm[i]=st.top()+1;
        }
        st.push(i);
        
      }
      stack<int>st2;
      for(int i=n-1;i>=0;i--)
      {
        while(!st2.empty() && heights[st2.top()]>=heights[i])
        {
            st2.pop();
        }
        if(st2.empty())
        {
            rm[i]=n-1;
        }
        else
        {
            rm[i]=st2.top()-1;
        }
        st2.push(i);
        
      }

      int maxi=0;
      for(int i=0;i<n;i++)
     { 
        maxi=max(maxi,(rm[i]-lm[i]+1)*heights[i]);
    }
      return maxi;
   }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>heights(m,0);
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    heights[j]+=1;
                }
                else
                {
                    heights[j]=0;
                }
            }
            int area=histo(heights);
            maxi=max(maxi,area);
        }
        return maxi;
    }
};