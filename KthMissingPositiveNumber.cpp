class Solution {
public:
    int findKthPositive(vector<int>& A, int k) {
        int l = 0, r = A.size(), m;
        while (l < r) {
            m = l+(r-l) / 2;
            if (A[m] - 1 - m < k)
                l = m + 1;
            else
                r = m;
        }
        int n=A.size();
        if(l>=n)
            return k+n;
        if(r<0)
            return k;
        return k+l;
    }
};
