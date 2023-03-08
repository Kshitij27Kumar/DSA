class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>pq;
        int min_val=INT_MAX;
        for(int num:nums){
            if(num%2)
                num*=2;
            pq.push(num);
            min_val=min(min_val,num);
        }
        int minDeviation=INT_MAX;
        while(true){
            int maxVal=pq.top();
            pq.pop();
            minDeviation=min(minDeviation, maxVal-min_val);
            if(maxVal%2)
                break;
            maxVal/=2;
            min_val=min(maxVal,min_val);
            pq.push(maxVal);
        }
        return minDeviation;
    }
};
