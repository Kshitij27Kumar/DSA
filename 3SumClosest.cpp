class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size=nums.size(),closet;
        sort(nums.begin(),nums.end());
        int diff=abs(target-(nums[0]+nums[1]+nums[2]));
        closet=nums[0]+nums[1]+nums[2];
            for(int i=0;i<size-2;i++){
            if(i == 0 || nums[i] != nums[i-1]){
                int first=i+1;
                int second=size-1;
                while(first<second){
                    int sum=nums[i]+nums[first]+nums[second];
                    if(sum==target){
                        return target;
                    }
                    else if(sum<target){
                        first++;
                    }
                        
                    else{
                        second--;
                    }
                    if(abs(target-sum)<diff){
                            diff=abs(target-sum);
                            closet=sum;
                    }   
                }
            } 
        }
        return closet;
    }
};
