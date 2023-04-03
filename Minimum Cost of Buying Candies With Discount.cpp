class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size();
        if(n==1)
            return cost[0];
        if(n==2)
            return cost[0]+cost[1];
        int ans=0,i;
        for(i=n-1;i>=2;i-=3){
            ans+=cost[i]+cost[i-1];
        }
        if(i==1)
            ans+=cost[i]+cost[i-1];
        else if(i==0)
            ans+=cost[i];
        return ans;
    }
};
