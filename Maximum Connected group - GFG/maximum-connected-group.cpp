//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet{
  public:
  vector<int>parent,size;
  DisjointSet(int n){
      parent.resize(n+1);
      size.resize(n+1,1);
      for(int i=0;i<=n;i++){
          parent[i]=i;
      }
  }
  int findParent(int x){
      if(x==parent[x])
        return x;
      return parent[x]=findParent(parent[x]);
  }
  void unionBySize(int u, int v){
      int upar=findParent(u);
      int vpar=findParent(v);
      if(upar==vpar) return;
      if(size[upar]>size[vpar]){
          parent[vpar]=upar;
          size[upar]+=size[vpar];
      } else{
          parent[upar]=vpar;
          size[vpar]+=size[upar];
      } 
  }
};
class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)  continue;
                int delRow[]={0,1,0,-1};
                int delCol[]={1,0,-1,0};
                for(int k=0;k<4;k++){
                    int nrow=delRow[k]+i, ncol=delCol[k]+j;
                    if(nrow<n && ncol<n && nrow>=0 && ncol>=0 && grid[nrow][ncol]==1){
                        int nodeNo=i*n+j;
                        int adjNode=nrow*n+ncol;
                        ds.unionBySize(nodeNo,adjNode);
                    } 
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    continue;
                int delRow[]={0,1,0,-1};
                int delCol[]={1,0,-1,0};
                unordered_set<int>s;
                for(int k=0;k<4;k++){
                    int nrow=delRow[k]+i, ncol=delCol[k]+j;
                    if(nrow<n && ncol<n && nrow>=0 && ncol>=0 && grid[nrow][ncol]==1){
                        s.insert(ds.findParent(nrow*n+ncol));
                    }
                }
                int totalSize=0;
                for(auto it:s){
                    totalSize+=ds.size[it];
                }
                ans=max(ans,totalSize+1);
            }
        }
        
        for(int i=0;i<n*n;i++){
            ans=max(ans,ds.size[ds.findParent(i)]);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends