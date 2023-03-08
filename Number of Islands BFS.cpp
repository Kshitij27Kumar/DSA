class Solution {
public:
    void bfs(vector<vector<char>>&grid, vector<vector<int>>&vis, int i, int j){
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        int n=grid.size(),m=grid[0].size();
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if((!i && j)||(i&&!j)){
                        int nrow=r+i;
                        int ncol=c+j;
                        if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]=='1'&&!vis[nrow][ncol]){
                            vis[nrow][ncol]=1;
                            q.push({nrow,ncol});
                        }
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    ans++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
};
