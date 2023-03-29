class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        reverse(satisfaction.begin(),satisfaction.end());
        int ans=0,n=satisfaction.size(),sum=0;
        for(int i=0;i<n;i++){
            if(sum+satisfaction[i]>0){
                ans+=sum+satisfaction[i];
                sum+=satisfaction[i];
            }
        }
        return ans;
    }
};
