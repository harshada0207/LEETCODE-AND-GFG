class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int mini=0;
        for(int i=0;i<n-k;i++)
        {
            mini+=cardPoints[i];    
        }
        int j=0;
        int sum=mini;
        for(int i=n-k;i<n;i++)
        {
            sum-=cardPoints[j];
            sum+=cardPoints[i];
            mini=min(sum,mini);
            j++;
        }
        int q=accumulate(cardPoints.begin(),cardPoints.end(),0);
        return q-mini;
    }
};