class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        pair<int,int>source={0,0};
        pair<int,int>dest={n-1,n-1};
        if(n==1)
            return 1;
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{source.first,source.second}});
        int delRow[]={0,0,1,-1,-1,1,-1,1};
        int delCol[]={-1,1,0,0,1,1,-1,-1};
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            for(int i=0;i<8;i++){
                int nrow=delRow[i]+r;
                int ncol=delCol[i]+c;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && dis+1<dist[nrow][ncol]){
                    dist[nrow][ncol]=dis+1;
                    if(nrow==dest.first && ncol==dest.second)
                        return dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
                
            }
        }
        return -1;
    }
};
