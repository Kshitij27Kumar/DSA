class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size(),m=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int startColor=image[sr][sc];
        if(startColor==newColor)
            return image;
        image[sr][sc]=newColor;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int x=-1;x<=1;x++){
                for(int y=-1;y<=1;y++){
                    if(!x&&y || !y&&x){
                        int nrow=r+x,ncol=c+y;
                        if(nrow<n&&ncol<m&&nrow>=0&&ncol>=0&&image[nrow][ncol]==startColor){
                        image[nrow][ncol]=newColor;
                        q.push({nrow,ncol});
                        }
                    }
                }
            }
        }
        return image;
    }
};
