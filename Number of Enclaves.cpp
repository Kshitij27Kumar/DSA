class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col, int n, int m){
        queue<pair<int,int>>q;
        q.push({row,col});
        int delRow[]={0,1,0,-1};
        int delCol[]={1,0,-1,0};
        vis[row][col]=1;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=x+delRow[i];
                int ncol=y+delCol[i];
                if(nrow<0 || nrow==n || ncol<0 || ncol==m)
                    continue;
                if(vis[nrow][ncol] || !grid[nrow][ncol])
                    continue;
                q.push({nrow,ncol});
                vis[nrow][ncol]=1;
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0])
                bfs(grid,vis,i,0,n,m);
            if(grid[i][m-1]==1 && !vis[i][m-1])
                bfs(grid,vis,i,m-1,n,m);
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j])
                bfs(grid,vis,0,j,n,m);
            if(grid[n-1][j]==1 && !vis[n-1][j])
                bfs(grid,vis,n-1,j,n,m);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1&&!vis[i][j])
                    ans++;
            }
        }
        return ans;
    }
};
