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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int countEdges=0;
        for(auto it:connections){
            int u=it[0], v=it[1];
            if(ds.findParent(u)==ds.findParent(v))
                countEdges++;
            else
                ds.unionBySize(u,v);
        }

        int numberComponents=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)
                numberComponents++;
        }
        int ans=numberComponents-1;
        if(countEdges>=ans)
            return ans;
        return -1;
    }
};
