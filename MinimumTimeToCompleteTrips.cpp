class Solution {
public:
    
    bool check(long long int mid,int t,vector<int>&time){
        long long int x=0;
        for(int i=0;i<time.size();i++){
            x+=mid/time[i];
        }
        return x>=t;
    }
    
    long long minimumTime(vector<int>& time, int t) {
       long long int ans=0,l=0,r=time[0]*(long long int)t;
        while(l<=r){
          long long int mid=(l+r)/2;
            if(check(mid,t,time)){
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    
    }
};
