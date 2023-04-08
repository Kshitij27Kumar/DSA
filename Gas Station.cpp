class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0,tsum=0,n=gas.size(),start=0;
        for(int i=0;i<n;i++)
        {
            sum+=gas[i]-cost[i];
            tsum+=gas[i]-cost[i];
            if(sum<0){
                sum=0;
                start=i+1;
            }
        }
        if(start==n || tsum<0)
            return -1;
        return start;
    }
};
