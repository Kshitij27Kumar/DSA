class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi=INT_MIN,n=candies.size();
        for(int i=0;i<n;i++)
            maxi=max(candies[i],maxi);
        vector<bool>res(n,false);
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=maxi){
                res[i]=true;
            }
        }
        return res;
    }
};
