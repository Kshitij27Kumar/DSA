//{ Driver Code Starts
// Initial Template for C++

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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int count=0;
        vector<int>ans;
        for(auto it:operators){
            int row=it[0], col=it[1];
            if(vis[row][col]==1){
                ans.push_back(count);
                continue;
            }
            vis[row][col]=1;
            count++;
            int dr[]={0,1,0,-1};
            int dc[]={1,0,-1,0};
            for(int i=0;i<4;i++){
                int adjR=row+dr[i];
                int adjC=col+dc[i];
                if(adjR<n && adjC<m && adjR>=0 && adjC>=0){
                    if(vis[adjR][adjC]==1){
                        int nodeNo=row*m+col;
                        int adjNodeNo=adjR*m+adjC;
                        if(ds.findParent(nodeNo)!=ds.findParent(adjNodeNo)){
                            count--;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends