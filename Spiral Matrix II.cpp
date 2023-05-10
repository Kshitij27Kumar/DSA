class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>grid(n,vector<int>(n,0));
        int up=0,down=n-1,left=0,right=n-1;
        int direction=1,num=1;
        while(up<=down&&left<=right){
            if(direction==1){
                for(int i=left;i<=right;i++){
                    grid[up][i]=num;
                    num++;
                }
                up++;
                direction=2;
            }
            else if(direction==2){
                for(int i=up;i<=down;i++){
                    grid[i][right]=num;
                    num++;
                }
                right--;
                direction=3;
            }
            else if(direction==3){
                for(int i=right;i>=left;i--){
                    grid[down][i]=num;
                    num++;
                }
                down--;
                direction=4;
            }
            else{
                for(int i=down;i>=up;i--){
                    grid[i][left]=num;
                    num++;
                }
                left++;
                direction=1;
            }
        }
        return grid;
    }
};
