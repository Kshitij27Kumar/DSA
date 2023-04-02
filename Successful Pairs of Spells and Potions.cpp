class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n=potions.size();
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++)
        {
            int s=0;
            int e=n-1;
            int mid;
            while(s<=e)
            {
                mid=e+(s-e)/2;
                if((long long)potions[mid]*spells[i]>=success)
                    e=mid-1;
                else
                    s=mid+1;
            }
            ans.push_back(n-e-1);
        }
        return ans;
    }
};
