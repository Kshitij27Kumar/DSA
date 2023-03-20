class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        int s=flowerbed.size();
        if(s==1&&flowerbed[0]==0)
            count=1;
        else if(s==1&& flowerbed[0]==1)
            count=0;
        else{
            for(int i=0;i<s;i++){
            if(i==0&&flowerbed[i]==0&&flowerbed[i+1]==0)
                flowerbed[i]=2;
            else if(i==s-1&&flowerbed[i]==0&&flowerbed[i-1]==0)
                flowerbed[i]=2;
            else if(i!=0 && i!=s-1&&flowerbed[i]==0 && flowerbed[i+1]==0&&flowerbed[i-1]==0){
                flowerbed[i]=2;
                
            }
        }
            for(int i=0;i<s;i++){
                if(flowerbed[i]==2)
                    count++;
            }
        }
        if(count<n)
            return false;
        return true;
    }
};
