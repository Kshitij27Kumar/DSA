class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        if(target==1)
            return 0;
        int res=0;
        while(maxDoubles>0 && target>1){
            if(target%2==0){
                target/=2;
                maxDoubles--;
            }
            else{
                target--;
            }
            res++;
        }
        if(maxDoubles==0)
            res+=(target-1);
        return res;
    }
};
