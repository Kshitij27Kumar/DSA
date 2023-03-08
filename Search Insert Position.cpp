class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        if(target<nums[0])
            return 0;
        if(target>nums[high])
            return high+1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            else if((nums[mid]>target&&nums[mid-1]<target))
                return mid;
            else if(nums[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return nums.size();
    }
};
