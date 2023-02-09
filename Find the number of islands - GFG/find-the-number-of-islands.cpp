// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int i, int j, vector<vector<char>>&grid, int n, int m){
        if(i<0||i>=n||j<0||j>=m||grid[i][j]!='1')
            return;
        grid[i][j]='2';
        for(int x=-1;x<=1;x++){
            for(int y=-1;y<=1;y++){
                int nrow=i+x,ncol=j+y;
                if(nrow>=0&& ncol>=0 && nrow<n && ncol<m&& grid[nrow][ncol]=='1')
                    dfs(nrow,ncol,grid,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid,n,m);
                    ans++;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends