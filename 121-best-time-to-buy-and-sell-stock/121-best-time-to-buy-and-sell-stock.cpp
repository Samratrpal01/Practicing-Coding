class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Min=INT_MAX,maxProfit=0;
    for(auto i:prices)
    {
        Min=min(i,Min);
        int profit=i-Min;
        maxProfit=max(profit,maxProfit);
        cout<<maxProfit<<" ";
    }
        return maxProfit;
    }
};