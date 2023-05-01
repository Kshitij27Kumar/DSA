class Solution {
public:
    double average(vector<int>& salary) {
        int minSal=INT_MAX;
        int maxSal=INT_MIN;
        double avgSal=0;
        long long sum=0;
        for(int i=0;i<salary.size();i++){
            minSal=min(minSal,salary[i]);
            maxSal=max(maxSal,salary[i]);
            sum+=salary[i];
        }
        avgSal=(double(sum-minSal-maxSal)/double(salary.size()-2));
        return avgSal;
    }
};
