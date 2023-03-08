class Solution {
public:
    int maximum69Number (int num) {
        int index=-1,i=0;
        vector<int>number;
        while(num>0){
            number.push_back(num%10);
            if(num%10==6)
                index=i;
            num/=10;
            i++;
        }
        if(index!=-1)
            number[index]=9;
        int ans=0;
        for(int i=number.size()-1;i>=0;i--){
            ans=ans*10+number[i];
        }
        return ans;
    }
};
