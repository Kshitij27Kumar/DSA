class Solution {
public:
    int reverse(int x) {
        long revInt = 0;
        int d;
        while(x != 0){
             d = x % 10;
             revInt  = (revInt * 10) + d;
             x /= 10;
        }
       if(revInt>INT_MAX || revInt<INT_MIN) return 0; // check 32 bit range 
        return int(revInt);
        }
};
