class Solution {
public:
    void bfs(vector<vector<char>> board,int i,int j,vector<vector<int>> &vis)
    {   int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        vis[i][j]=1;
        q.push({i,j});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        while(!q.empty())
        {
            int si=q.front().first;
            int sj=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=si+delrow[i];
                int ncol=sj+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && board[nrow][ncol]=='O' && vis[nrow][ncol]==0)
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O' && vis[0][i]==0)
                bfs(board,0,i,vis);

            if(board[n-1][i]=='O' && vis[n-1][i]==0)
                bfs(board,n-1,i,vis);
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O' && vis[i][0]==0)
                bfs(board,i,0,vis);
            
            if(board[i][m-1]=='O' && vis[i][m-1]==0)
                bfs(board,i,m-1,vis);   
        }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(board[i][j]=='O' && vis[i][j]==0)
                    board[i][j]='X';
        
    }
};
