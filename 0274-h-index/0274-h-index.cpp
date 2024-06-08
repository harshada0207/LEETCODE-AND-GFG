class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int maxi = 0;
        int n=citations.size();
        sort(citations.begin(),citations.end());
       
       int ind=0;
        while(ind<n && citations[ind]==0)
        {
            ind++;
        }
        if(ind==n)
        {
            return 0;
        }
        if(n-ind<=citations[ind])
        {
            return n-ind;
        }
            
        for(int i =ind;i<n;i++)
        {
            if(citations[i]>n-i)
            {
                maxi = max(maxi,n-i);
            }
            else 
            {
                 maxi = max(maxi,citations[i]);
            }
           
        }
        return maxi;
    }
};