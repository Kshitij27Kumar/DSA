class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sum=0,c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                sum+=(c*(c+1))/2;
                c=0;
            }
            else if(nums[i]==0)
                c++;
        }
        if(c!=0)
            sum+=(c*(c+1))/2;
        return sum;
    }
};
