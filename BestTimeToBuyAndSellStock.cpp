class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxs=0,currs=0;
        for(int i=1;i<prices.size();i++)
        {
            currs=max(0,currs+=prices[i]-prices[i-1]);
            maxs=max(maxs,currs);
        }
        return maxs;
    }
};
