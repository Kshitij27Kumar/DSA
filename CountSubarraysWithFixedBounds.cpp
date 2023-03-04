class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int leftBound=-1, maxBound=-1, minBound=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=minK && nums[i]<=maxK){
                minBound=(nums[i]==minK)?i:minBound;
                maxBound=(nums[i]==maxK)?i:maxBound;
                ans+=max(0,min(minBound,maxBound)-leftBound);
            }
            else{
                leftBound=i;
                minBound=-1;
                maxBound=-1;
            }
        }
        return ans;
    }
};
