class Solution {
private:
    int findSum(int num, int sum){
        while(num>0){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
public:
    int addDigits(int num) {
        while(num>9){
            num=findSum(num,0);
        }
        return num;
    }
};
