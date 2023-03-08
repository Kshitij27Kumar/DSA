class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i=0,j=n,k=0;
        vector<int>ans(2*n);
        for(;i<n;i++,j++){
            ans[k++]=nums[i];
            ans[k++]=nums[j];
        }
        return ans;
    }
};
