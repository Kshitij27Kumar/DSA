class Solution {
private:
    void helper(vector<int>&candidates, int target, vector<vector<int>>&ans, vector<int>&subans, int index){
        if(index==candidates.size()){
            if(target==0)
                ans.push_back(subans);
            return;
        }
        if(candidates[index]<=target){
            subans.push_back(candidates[index]);
            helper(candidates,target-candidates[index],ans,subans,index);
            subans.pop_back();
        }
        helper(candidates,target,ans,subans,index+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>subans;
        helper(candidates,target,ans,subans,0);
        return ans;
    }
};
