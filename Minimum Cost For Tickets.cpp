class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[366]={0};
        int i=0;
        for(int j=1;j<=days.back();j++){
            if(days[i]==j){
                dp[j]=dp[j-1]+costs[0];
                dp[j]=min(dp[j],dp[max(0,j-7)]+costs[1]);
                dp[j]=min(dp[j],dp[max(0,j-30)]+costs[2]);
                i++;
            }
            else{
                dp[j]=dp[j-1];
            }
        }
        return dp[days.back()];
    }
};
