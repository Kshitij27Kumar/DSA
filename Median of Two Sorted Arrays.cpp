class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double>v;
        int n=nums1.size(),m=nums2.size();
        for(int i=0;i<n;i++){
            v.push_back((double)nums1[i]);
        }
        for(int i=0;i<m;i++){
            v.push_back((double)nums2[i]);
        }
        sort(v.begin(),v.end());
        if((n+m)%2)
            return v[(n+m)/2];
        return (v[(n+m-1)/2]+v[(n+m)/2])/2.0;
    }
};
