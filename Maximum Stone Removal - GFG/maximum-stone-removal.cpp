//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

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
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int maxRow=0, maxCol=0;
        for(auto it:stones){
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int>stoneNodes;
        for(auto it:stones){
            int nodeRow=it[0];
            int nodeCol=it[1]+maxRow+1;
            ds.unionBySize(nodeRow,nodeCol);
            stoneNodes[nodeRow]=1;
            stoneNodes[nodeCol]=1;
        }
        
        int count=0;
        for(auto it:stoneNodes){
            if(ds.findParent(it.first)==it.first)
                count++;
        }
        
        return n-count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends