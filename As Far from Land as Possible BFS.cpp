class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int res=0, n=grid.size(),m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                if(grid[i][j])
                    q.push({i,j});
        }
        while(!q.empty()){
            pair<int,int>curr=q.front();
            q.pop();
            pair<int,int>dirs[4]={{0,1},{0,-1},{1,0},{-1,0}};
            for(auto dir:dirs){
                int x=dir.first+curr.first;
                int y=dir.second+curr.second;
                if(x>=0&&x<n&&y>=0&&y<m&&grid[x][y]==0){
                    q.push({x,y});
                    grid[x][y]=grid[curr.first][curr.second]+1;
                    res=max(grid[x][y],res);
                }
            }
        }
        return res>0?res-1:-1;
    }
};
