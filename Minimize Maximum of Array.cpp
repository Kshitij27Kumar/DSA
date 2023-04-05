class Solution {
public:
    int max(int a, int b){
        return a>b?a:b;
    }
    int minimizeArrayValue(vector<int>& nums) {
        long long sum=0,ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            long long avg=ceil((sum)/(i+1.0));
            ans=max(ans,avg);
        }
        return ans;
    }
};
