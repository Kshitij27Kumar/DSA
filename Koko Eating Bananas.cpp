class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxi=0;
        for(int x:piles){
            maxi=max(maxi,x);
        }
        int left=1, right=maxi;
        while(left<right){
            int mid=left+(right-left)/2;
            int count=0;
            for(int x:piles){
                count+=(x+mid-1)/mid;
            }
            if(count>h)
                left=mid+1;
            else
                right=mid;
        }

        return left;
    }
};
