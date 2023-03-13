class Solution {
private:
    void findOtherIndexes(vector<int>&nums, int reqSum,int idx, vector<vector<int>>&ans){
        int start=idx+1, end=nums.size()-1;
        while(start<end){
            if(nums[start]+nums[end]==reqSum){
                vector<int>temp;
                temp.push_back(nums[idx]);
                temp.push_back(nums[start]);
                temp.push_back(nums[end]);
                ans.push_back(temp);
                int second=nums[start];
                int third=nums[end];
                start++, end--;
                while(start<nums.size()&&nums[start]==second)  start++;
                while(end>=0 && nums[end]==third)  end--;
            }
            else if(nums[start]+nums[end]>reqSum)
                end--;
            else
                start++;
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int i=0,n=nums.size();
        while(i<n){
            int first=nums[i];
            int req_sum=(-1)*first;
            findOtherIndexes(nums,req_sum,i,ans);
            while(i<n && nums[i]==first)  i++;
        }
        return ans;
    }
};
