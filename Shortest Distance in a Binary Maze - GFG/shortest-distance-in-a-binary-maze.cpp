//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(source.first==destination.first && source.second==destination.second)
            return 0;
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{source.first,source.second}});
        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};
        while(!q.empty()){
            int dis=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nRow=delRow[i]+r;
                int nCol=delCol[i]+c;
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m &&grid[nRow][nCol]==1 && dis+1 < dist[nRow][nCol]){
                    dist[nRow][nCol]=dis+1;
                    if(nRow==destination.first && nCol==destination.second)
                        return dis+1;
                    q.push({dis+1,{nRow,nCol}});
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends