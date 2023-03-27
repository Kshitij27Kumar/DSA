class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), i, j;
        for(i=1; i<n; i++) 
            grid[i][0] += grid[i-1][0];
        for(j=1; j<m; j++)
            grid[0][j] += grid[0][j-1];
        for(i=1; i<n; i++) 
            for(j=1; j<m; j++) 
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        return grid[n-1][m-1];
    }
};
