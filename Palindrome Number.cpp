class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long rev=0;
        long temp=x;
        while(x>0)
        {
            int t=x%10;
            rev=rev*10+t;
            x/=10;
            cout<<rev<<endl;
        }
        if(rev==temp)
            return true;
        return false;
    }
};
