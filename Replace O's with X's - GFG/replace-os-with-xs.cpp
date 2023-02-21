//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(vector<vector<char>>& mat, vector<vector<int>>& vis, int row, int col, int n, int m) 
    {
        if(row<0 || row==n || col<0 || col==m || vis[row][col] || mat[row][col]=='X')
            return;
            
        vis[row][col] = 1;
        
        dfs(mat, vis, row+1, col, n, m);
        dfs(mat, vis, row, col+1, n, m);
        dfs(mat, vis, row-1, col, n, m);
        dfs(mat, vis, row, col-1, n, m);
    }


    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' && !vis[i][0]){
                dfs(mat,vis,i,0,n,m);
            }
            if(mat[i][m-1]=='O' && !vis[i][m-1]){
                dfs(mat,vis,i,m-1,n,m);
            }
        }
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O' && !vis[0][i]){
                dfs(mat,vis,0,i,n,m);
            }
            if(mat[n-1][i]=='O' && !vis[n-1][i]){
                dfs(mat,vis,n-1,i,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]=='O')
                    mat[i][j]='X';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends