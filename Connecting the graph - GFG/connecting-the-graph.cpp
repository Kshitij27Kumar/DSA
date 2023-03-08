//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    
    public:
    vector<int>parent, rank, size;
        DisjointSet(int n){
            rank.resize(n+1,0);
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<=n;i++)
                parent[i]=i;
        }
        int findParent(int x){
            if(x==parent[x])
                return x;
            return parent[x]=findParent(parent[x]);
        }
        void unionByRank(int u, int v){
            int uPar=findParent(u);
            int vPar=findParent(v);
            if(uPar==vPar)
                return;
            if(rank[uPar]<rank[vPar]){
                parent[uPar]=vPar;
            }
            else if(rank[uPar]>rank[vPar]){
                parent[vPar]=uPar;
            }
            else{
                parent[vPar]=uPar;
                rank[uPar]++;
            }
        }
        void unionBySize(int u, int v){
            int uPar=findParent(u);
            int vPar=findParent(v);
            if(uPar==vPar)  return;
            if(size[uPar]>size[vPar]){
                parent[vPar]=uPar;
                size[uPar]+=size[vPar];
            } else{
                parent[uPar]=vPar;
                size[vPar]+=size[uPar];
            }
        }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        DisjointSet ds(n);
        int countExtraEdges=0;
        for(auto it:edge){
            int u=it[0];
            int v=it[1];
            if(ds.findParent(u)==ds.findParent(v))
                countExtraEdges++;
            else{
                ds.unionByRank(u,v);
                //ds.unionBySize(u,v);
            }
        }
        int countComponents=0;
        for(int i=0;i<n;i++)
            if(ds.parent[i]==i)
                countComponents++;
        int ans=countComponents-1;
        if(countExtraEdges>=ans)
            return ans;
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
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends