//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>&vis, int row, int col, int n, int m){
        if(row<0 || row>=n || col<0 || col>=m || vis[row][col] || !grid[row][col])
            return;
        vis[row][col]=1;
        dfs(grid,vis,row+1,col,n,m);
        dfs(grid,vis,row,col+1,n,m);
        dfs(grid,vis,row-1,col,n,m);
        dfs(grid,vis,row,col-1,n,m);
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0])
                dfs(grid,vis,i,0,n,m);
            if(grid[i][m-1]==1 && !vis[i][m-1])
                dfs(grid,vis,i,m-1,n,m);
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j])
                dfs(grid,vis,0,j,n,m);
            if(grid[n-1][j]==1 && !vis[n-1][j])
                dfs(grid,vis,n-1,j,n,m);
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


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends