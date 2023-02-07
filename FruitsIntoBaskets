class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int i,j;
        int n=fruits.size();
        for(i=0,j=0;j<n;j++){
            mp[fruits[j]]++;
            if(mp.size()>2){
                if(--mp[fruits[i]]==0)
                    mp.erase(fruits[i]);
                i++;
            }
        }
        return j-i;
    }
};
