class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,vector<int>>mp;
        for(auto p:pieces){
            mp[p[0]]=p;
        }
        vector<int>result;
        for(auto a:arr){
            if(mp.find(a)!=mp.end()){
                result.insert(result.end(),mp[a].begin(),mp[a].end());
            }
        }
        return result==arr;
    }
};
