class Solution {
public:
    int sumOfDigits(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int>ump;
        for(int i=1;i<=n;i++){
            int sum_dig=sumOfDigits(i);
            ump[sum_dig]++;
        }
        int max_freq=INT_MIN, count=0;
        for(auto it:ump){
            if(it.second>max_freq){
                max_freq=it.second;
                count=1;
            }else if(it.second==max_freq)
                count++;
        }
        return count;
    }
};
