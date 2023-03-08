class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo=*max_element(weights.begin(),weights.end());
        int hi=accumulate(weights.begin(),weights.end(),0);
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            int curr=0, need_days=1;
            for(int w:weights){
                if(curr+w>mid){
                    need_days++;
                    curr=0;
                }
                curr+=w;
            }
            if(need_days<=days)
                hi=mid;
            else
                lo=mid+1;
        }
        return lo;
    }
};
